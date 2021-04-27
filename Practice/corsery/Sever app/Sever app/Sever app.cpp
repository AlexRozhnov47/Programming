// Sever app.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <winsock2.h>

#define MAX_PACKET_SIZE    0x10000
#define SIO_RCVALL         0x98000001
// Буфер для приёма данных
char Buffer[MAX_PACKET_SIZE]; // 64 Kb

using namespace std;

//Структура заголовка IP-пакета

#define MAX_PACKET_SIZE    0x10000
#define SIO_RCVALL         0x98000001
// Буфер для приёма данных
char Buffer[MAX_PACKET_SIZE]; // 64 Kb

using namespace std;

//Структура заголовка IP-пакета

typedef struct IPHeader {
	UCHAR   iph_verlen;   // версия и длина заголовка
	UCHAR   iph_tos;      // тип сервиса
	USHORT  iph_length;   // длина всего пакета
	USHORT  iph_id;       // Идентификация
	USHORT  iph_offset;   // флаги и смещения
	UCHAR   iph_ttl;      // время жизни пакета
	UCHAR   iph_protocol; // протокол
	USHORT  iph_xsum;     // контрольная сумма
	ULONG   iph_src;      // IP-адрес отправителя
	ULONG   iph_dest;     // IP-адрес назначения
} IPHeader;

char src[10];
char dest[10];
char ds[15];
char dso[5];
unsigned short lowbyte;
unsigned short hibyte;

int main()
{
	WSADATA     wsadata;   // Инициализация WinSock.
	SOCKET      s;         // Cлущающий сокет.
	char        name[128]; // Имя хоста (компьютера).
	HOSTENT* phe;       // Информация о хосте.
	SOCKADDR_IN sa;        // Адрес хоста
	IN_ADDR sa1;        //
	unsigned long        flag = 1;  // Флаг PROMISC Вкл/выкл.

	// инициализация
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	s = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	gethostname(name, sizeof(name));
	phe = gethostbyname(name);
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = ((struct in_addr*)phe->h_addr_list[0])->s_addr;
	bind(s, (SOCKADDR*)&sa, sizeof(SOCKADDR));

	// Включение promiscuous mode.
	ioctlsocket(s, SIO_RCVALL, &flag);

	// Бесконечный цикл приёма IP-пакетов.
	while (0 == 0)
	{
		int count;
		count = recv(s, Buffer, sizeof(Buffer), 0);
		// обработка IP-пакета
		if (count >= sizeof(IPHeader))
		{
			IPHeader* hdr = (IPHeader*)Buffer;
			//Начинаем разбор пакета...

			strcpy(src, "pack: ");
			CharToOem(src, dest);
			printf(dest);
			// Преобразуем в понятный вид адрес отправителя.
			printf("From ");
			sa1.s_addr = hdr->iph_src;
			printf(inet_ntoa(sa1));

			// Преобразуем в понятный вид адрес получателя.
			printf(" To ");
			sa1.s_addr = hdr->iph_dest;
			printf(inet_ntoa(sa1));

			// Вычисляем протокол. Полный список этих констант
			// содержится в файле winsock2.h
			printf(" Prot: ");
			if (hdr->iph_protocol == IPPROTO_TCP) printf("TCP "); else
				if (hdr->iph_protocol == IPPROTO_UDP) printf("UDP "); else
					printf("UNKNOWN ");

			// Вычисляем размер. Так как в сети принят прямой порядок
			// байтов, а не обратный, то прийдётся поменять байты местами.
			printf("Size: ");
			lowbyte = hdr->iph_length >> 8;
			hibyte = hdr->iph_length << 8;
			hibyte = hibyte + lowbyte;
			printf("%s", itoa(hibyte, ds, 10));

			// Вычисляем время жизни пакета.
			printf("%s", itoa(hibyte, ds, 10));
			printf(" TTL:%s", itoa(hdr->iph_ttl, ds, 10));

			cout << endl;
		}
	}

	closesocket(s);
	WSACleanup();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
