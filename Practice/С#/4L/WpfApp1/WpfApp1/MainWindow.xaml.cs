using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SwitchDevices
{
    /// <summary>
    /// Status of coolant system enumeration
    /// Check indicates a manual check needs to be performed by the operator
    /// </summary>
    public enum CoolantSystemStatus { OK, Check, Fail }

    /// <summary>
    /// Success or failure result enumeration
    /// </summary>
    public enum SuccessFailureResult { Success, Fail }

    /// <summary>
    /// Switch class - manages interaction with physical switch hardware
    /// </summary>
    public class Switch
    {
        /// <summary>
        /// Utilty object for simulation
        /// </summary>
        private Random rand = new Random();

        /// <summary>
        /// Disconnect from the external power generation systems
        /// </summary>
        /// <returns>Success or Failure</returns>
        /// <exception cref="PowerGeneratorCommsException">Thrown when the physical switch cannot establish a connection to the power generation system</exception>
        public SuccessFailureResult DisconnectPowerGenerator()
        {
            SuccessFailureResult r = SuccessFailureResult.Fail;
            if (rand.Next(1, 10) > 2) r = SuccessFailureResult.Success;
            if (rand.Next(1, 20) > 18) throw new PowerGeneratorCommsException("Network failure accessing Power Generator monitoring system");
            return r;
        }

        /// <summary>
        /// Runs a diagnostic check against the primary coolant system
        /// </summary>
        /// <returns>Coolant System Status (OK, Fail, Check)</returns>
        /// <exception cref="CoolantTemperatureReadException">Thrown when the switch cannot read the temperature from the coolant system</exception>
        /// <exception cref="CoolantPressureReadException">Thrown when the switch cannot read the pressure from the coolant system</exception>
        public CoolantSystemStatus VerifyPrimaryCoolantSystem()
        {
            CoolantSystemStatus c = CoolantSystemStatus.Fail;
            int r = rand.Next(1, 10);
            if (r > 5)
            {
                c = CoolantSystemStatus.OK;
            }
            else if (r > 2)
            {
                c = CoolantSystemStatus.Check;
            }
            if (rand.Next(1, 20) > 18) throw new CoolantTemperatureReadException("Failed to read primary coolant system temperature");
            if (rand.Next(1, 20) > 18) throw new CoolantPressureReadException("Failed to read primary coolant system pressure");
            return c;
        }

        /// <summary>
        /// Runs a diagnostic check against the backup coolant system
        /// </summary>
        /// <returns>Coolant System Status (OK, Fail, Check)</returns>
        /// <exception cref="CoolantTemperatureReadException">Thrown when the switch cannot read the temperature from the coolant system</exception>
        /// <exception cref="CoolantPressureReadException">Thrown when the switch cannot read the pressure from the coolant system</exception>
        public CoolantSystemStatus VerifyBackupCoolantSystem()
        {
            CoolantSystemStatus c = CoolantSystemStatus.Fail;
            int r = rand.Next(1, 10);
            if (r > 5)
            {
                c = CoolantSystemStatus.OK;
            }
            else if (r > 2)
            {
                c = CoolantSystemStatus.Check;
            }
            if (rand.Next(1, 20) > 19) throw new CoolantTemperatureReadException("Failed to read backup coolant system temperature");
            if (rand.Next(1, 20) > 19) throw new CoolantPressureReadException("Failed to read backup coolant system pressure");
            return c;
        }

        /// <summary>
        /// Reads the temperature from the reactor core
        /// </summary>
        /// <returns>Temperature</returns>
        /// <exception cref="CoreTemperatureReadException">Thrown when the switch cannot access the temperature data</exception>
        public double GetCoreTemperature()
        {
            if (rand.Next(1, 20) > 18) throw new CoreTemperatureReadException("Failed to read core reactor system temperature");
            return rand.NextDouble() * 1000;
        }

        /// <summary>
        /// Instructs the reactor to insert the control rods to shut the reactor down
        /// </summary>
        /// <returns>Success or failure</returns>
        /// <exception cref="RodClusterReleaseException">Thrown if the switch device cannot read the rod position</exception>
        public SuccessFailureResult InsertRodCluster()
        {
            SuccessFailureResult r = SuccessFailureResult.Fail;
            if (rand.Next(1, 100) > 5) r = SuccessFailureResult.Success;
            if (rand.Next(1, 10) > 8) throw new RodClusterReleaseException("Sensor failure, cannot verify rod release");
            return r;
        }

        /// <summary>
        /// Reads the radiation level from the reactor core
        /// </summary>
        /// <returns>Temperature</returns>
        /// <exception cref="CoreRadiationLevelReadException">Thrown when the switch cannot access the radiation level data</exception>
        public double GetRadiationLevel()
        {
            if (rand.Next(1, 20) > 18) throw new CoreRadiationLevelReadException("Failed to read core reactor system radiation levels");
            return rand.NextDouble() * 500;
        }

        /// <summary>
        /// Sends a broadcast message to PA system notofying shutdown complete
        /// </summary>
        /// <exception cref="SignallingException">Thrown if the switch cannot connect to the PA system over the network</exception>
        public void SignalShutdownComplete()
        {
            if (rand.Next(1, 20) > 18) throw new SignallingException("Network failure connecting to broadcast systems");
        }
    }

    public class PowerGeneratorCommsException : Exception
    {
        public PowerGeneratorCommsException(string message) : base(message) { }
    }

    public class CoolantSystemException : Exception
    {
        public CoolantSystemException(string message) : base(message) { }
    }

    public class CoolantTemperatureReadException : CoolantSystemException
    {
        public CoolantTemperatureReadException(string message) : base(message) { }
    }

    public class CoolantPressureReadException : CoolantSystemException
    {
        public CoolantPressureReadException(string message) : base(message) { }
    }

    public class CoreTemperatureReadException : Exception
    {
        public CoreTemperatureReadException(string message) : base(message) { }
    }

    public class CoreRadiationLevelReadException : Exception
    {
        public CoreRadiationLevelReadException(string message) : base(message) { }
    }

    public class RodClusterReleaseException : Exception
    {
        public RodClusterReleaseException(string message) : base(message) { }
    }

    public class SignallingException : Exception
    {
        public SignallingException(string message) : base(message) { }
    }
}
namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.textBlock1.Text = "Инициализация тестирования: " + DateTime.Now.ToLongTimeString();
            SwitchDevices.Switch sd = new SwitchDevices.Switch();

            // Step 1 - disconnect from the Power Generator
            if (sd.DisconnectPowerGenerator() == SwitchDevices.SuccessFailureResult.Fail)
            {
                this.textBlock1.Text += "\nШАГ 1: Не удалось отключиться от системы питания";
            }
            else
            {
                this.textBlock1.Text += "\nШаг 1: Успешен перевод в режим выключения";
            }


            // Step 2 - Verify the status of the Primary Coolant System
            switch (sd.VerifyPrimaryCoolantSystem())
            {
                case SwitchDevices.CoolantSystemStatus.OK:
                    this.textBlock1.Text += "\nШаг 2: Система охлаждения в норме";
                    break;
                case SwitchDevices.CoolantSystemStatus.Check:
                    this.textBlock1.Text += "\nШаг 2: Система охлаждения требует проверки";
                    break;
                case SwitchDevices.CoolantSystemStatus.Fail:
                    this.textBlock1.Text += "\nШаг 2: Неустранимый отказ системы охлаждения ";
                    break;
            }


            // Step 3 - Verify the status of the Backup Coolant System
            switch (sd.VerifyBackupCoolantSystem())
            {
                case SwitchDevices.CoolantSystemStatus.OK:
                    this.textBlock1.Text += "\nШаг 3: Дополнительная Система охлаждения в норме";
                    break;
                case SwitchDevices.CoolantSystemStatus.Check:
                    this.textBlock1.Text += "\nШаг 3: Дополнительная Система охлаждения требует проверки";
                    break;
                case SwitchDevices.CoolantSystemStatus.Fail:
                    this.textBlock1.Text += "\nШаг 3: Отказ доп. охлаждения";
                    break;
            }


            // Step 4 - Record the core temperature prior to shutting down the reactor
            this.textBlock1.Text += "\nШаг 4: Температура ЦП: " + sd.GetCoreTemperature();


            // Step 5 - Insert the control rods into the reactor
            if (sd.InsertRodCluster() == SwitchDevices.SuccessFailureResult.Success)
            {
                this.textBlock1.Text += "\nШаг 5: Проверка целостности пьезо-элементов успешна";
            }
            else
            {
                this.textBlock1.Text += "\nШаг 5: Проверка целостности пьезо-элементов провалена";
            }

            // Step 6 - Record the core temperature after shutting down the reactor
            this.textBlock1.Text += "\nШаг 6: Тепература после выключения: " + sd.GetCoreTemperature();


            // Step 7 - Record the core radiation levels after shutting down the reactor
            this.textBlock1.Text += "\nШаг 7: Температура радиатора после выключения: " + sd.GetRadiationLevel();


            // Step 8 - Broadcast "Shutdown Complete" message
            sd.SignalShutdownComplete();
            this.textBlock1.Text += "\nШаг 8: НЕ забудьте выключитть компьютер";


            this.textBlock1.Text += "\nТестирование завершено: " + DateTime.Now.ToLongTimeString();
        }
    }
}
