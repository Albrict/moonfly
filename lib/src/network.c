#include "network.h"
#include "mdns.h"

bool InitNetwork(const int port, const char *service, const char *hostname)
{
    mdns_query_t query[16];
    size_t       queryCount = 0;
#ifdef _WIN32
    WORD    versionWanted = MAKEWORD(1, 1);
    WSADATA wsaData;
	if (WSAStartup(versionWanted, &wsaData)) {
		fprintf(stderr, "Failed to initialize WinSock\n");
		return false;
	}
    if (hostname == NULL) {
        char  hostnameBuffer[256];
        DWORD hostnameSize = (DWORD)sizeof(hostnameBuffer);
        if (GetComputerNameA(hostname_buffer, &hostname_size))
            hostname = hostname_buffer;
    }
#else
    if (hostname == NULL) {
        char hostnameBuffer[256];
        size_t hostnameSize = sizeof(hostnameBuffer);
        if (gethostname(hostnameBuffer, hostnameSize) == 0)
            hostname = hostnameBuffer;
    }
#endif
    return true;
}

void CloseNetwork()
{
#ifdef _WIN32
    WSACleanup();
#endif
}
