#pragma once
#include "AppPartOpsExports.h"
#include "../LibCore/IObserver.h"

class APPPARTOPS_API PartObserver : public IObserver {
	void PrintInfo();
	void PrintInfo(void* data);
};