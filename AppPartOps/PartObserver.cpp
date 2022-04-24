#include "PartObserver.h"
#include "..\AppPartOps\DelMeBadPattern.h"
#include <iostream>

void PartObserver::PrintInfo() {
	std::cout << "Part Observer \"" << "\": a new part message is available --> " << "some message about this part." << "\n";

}

void PartObserver::PrintInfo(void* data) {
	PartOpsNotifierData* partData = (PartOpsNotifierData*)data;

	std::cout << "Part Observer \"" << "\": a new message is available --> " << "some message about this part." << "\n";
	std::cout << "Part Data \n" << "Part FilePath " << partData->partName << "\nPart GUID " << partData->guid << std::endl;

}