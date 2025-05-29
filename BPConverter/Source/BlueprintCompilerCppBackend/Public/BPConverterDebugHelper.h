#pragma once

#include "CoreMinimal.h"

#define ENABLE_BP_CONVERTER_DEBUG_HELPER 1

DECLARE_LOG_CATEGORY_CLASS(LogBPConverter, Log, All);

#if ENABLE_BP_CONVERTER_DEBUG_HELPER
#define BP_CONVERTER_DEBUG(msg) ((void)(UE_DEBUG_BREAK()))
#else
#define BP_CONVERTER_DEBUG(msg) UE_LOG(LogBPConverter, Warning, TEXT(msg))
#endif