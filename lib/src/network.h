#pragma once
#include <moonfly.h>

bool InitNetwork(const int port, const char *service, const char *hostname);
void CloseNetwork(void);
bool Discover(void);
