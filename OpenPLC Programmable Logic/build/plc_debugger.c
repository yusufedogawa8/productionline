/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */
#ifdef TARGET_DEBUG_AND_RETAIN_DISABLE

void __init_debug    (void){}
void __cleanup_debug (void){}
void __retrieve_debug(void){}
void __publish_debug (void){}

#else

#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

typedef unsigned int dbgvardsc_index_t;
typedef unsigned short trace_buf_offset_t;

#define BUFFER_EMPTY 0
#define BUFFER_FULL 1

#ifndef TARGET_ONLINE_DEBUG_DISABLE

#define TRACE_BUFFER_SIZE 4096
#define TRACE_LIST_SIZE 1024

/* Atomically accessed variable for buffer state */
static long trace_buffer_state = BUFFER_EMPTY;

typedef struct trace_item_s {
    dbgvardsc_index_t dbgvardsc_index;
} trace_item_t;

trace_item_t trace_list[TRACE_LIST_SIZE];
char trace_buffer[TRACE_BUFFER_SIZE];

/* Trace's cursor*/
static trace_item_t *trace_list_collect_cursor = trace_list;
static trace_item_t *trace_list_addvar_cursor = trace_list;
static const trace_item_t *trace_list_end = 
    &trace_list[TRACE_LIST_SIZE-1];
static char *trace_buffer_cursor = trace_buffer;
static const char *trace_buffer_end = trace_buffer + TRACE_BUFFER_SIZE;



#define FORCE_BUFFER_SIZE 1024
#define FORCE_LIST_SIZE 256

typedef struct force_item_s {
    dbgvardsc_index_t dbgvardsc_index;
    void *value_pointer_backup;
} force_item_t;

force_item_t force_list[FORCE_LIST_SIZE];
char force_buffer[FORCE_BUFFER_SIZE];

/* Force's cursor*/
static force_item_t *force_list_apply_cursor = force_list;
static force_item_t *force_list_addvar_cursor = force_list;
static const force_item_t *force_list_end = 
    &force_list[FORCE_LIST_SIZE-1];
static char *force_buffer_cursor = force_buffer;
static const char *force_buffer_end = force_buffer + FORCE_BUFFER_SIZE;


#endif

/***
 * Declare programs 
 **/
extern PROJEK_MEKATRONIKA_KOMPLEKS RES0__INSTANCE0;

/***
 * Declare global variables from resources and conf 
 **/
extern       PROJEK_MEKATRONIKA_KOMPLEKS   RES0__INSTANCE0;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static const dbgvardsc_t dbgvardsc[] = {
{&(RES0__INSTANCE0.SENSORTINGGI), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORRENDAH), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORPALLET), BOOL_ENUM},
{&(RES0__INSTANCE0.LOADED), BOOL_ENUM},
{&(RES0__INSTANCE0.ENTRYKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.EXITKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.ENTRYKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.EXITKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.BERHENTIDARURAT), BOOL_ENUM},
{&(RES0__INSTANCE0.START), BOOL_ENUM},
{&(RES0__INSTANCE0.RESET), BOOL_ENUM},
{&(RES0__INSTANCE0.STOP), BOOL_ENUM},
{&(RES0__INSTANCE0.FACTORYBERJALAN), BOOL_ENUM},
{&(RES0__INSTANCE0.MANUAL), BOOL_ENUM},
{&(RES0__INSTANCE0.AUTO), BOOL_ENUM},
{&(RES0__INSTANCE0.PALLETSENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORPICKPLACEKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORRENDAHKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORTINGGIKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORPICKPLACEKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORSTOPPER), BOOL_ENUM},
{&(RES0__INSTANCE0.ENTRYCONVEYOR), BOOL_ENUM},
{&(RES0__INSTANCE0.LOAD), BOOL_ENUM},
{&(RES0__INSTANCE0.UNLOAD), BOOL_ENUM},
{&(RES0__INSTANCE0.KEKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.KEKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.CONVEYORKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.CONVEYORKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.EMITTER), BOOL_ENUM},
{&(RES0__INSTANCE0.REMOVERKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.REMOVERKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.LAMPUSTART), BOOL_ENUM},
{&(RES0__INSTANCE0.LAMPURESET), BOOL_ENUM},
{&(RES0__INSTANCE0.LAMPUSTOP), BOOL_ENUM},
{&(RES0__INSTANCE0.CONVEYORKANANBELOKKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.CONVEYORPICKPLACEKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.AMBILKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.BCKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.BCKANANNAIK), BOOL_ENUM},
{&(RES0__INSTANCE0.BCKIRINAIK), BOOL_ENUM},
{&(RES0__INSTANCE0.BCKIRI1), BOOL_ENUM},
{&(RES0__INSTANCE0.BCPALLETIZER), BOOL_ENUM},
{&(RES0__INSTANCE0.PUSHERKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.AMBILKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.MUTERKIRI), BOOL_ENUM},
{&(RES0__INSTANCE0.STOPPER), BOOL_ENUM},
{&(RES0__INSTANCE0.AUTOMODE), BOOL_ENUM},
{&(RES0__INSTANCE0.RESETMODE), BOOL_ENUM},
{&(RES0__INSTANCE0.MANUALMODE), BOOL_ENUM},
{&(RES0__INSTANCE0.RUNNINGMODE), BOOL_ENUM},
{&(RES0__INSTANCE0.STARTLATCH), BOOL_ENUM},
{&(RES0__INSTANCE0.PALLETSENSORMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORRENDAHMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORTINGGIMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORRENDAHRESET), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORTINGGIRESET), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORRENDAHKANANMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORTINGGIKANANMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.PINDAHBOXKANANMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.BALIKTEMPATKANANMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.SENSORRESETKANAN), BOOL_ENUM},
{&(RES0__INSTANCE0.PINDAHBOXKIRIMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.BALIKTEMPATKIRIMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.LEPASKIRIMEM), BOOL_ENUM},
{&(RES0__INSTANCE0.PUSHERRESET), BOOL_ENUM},
{&(RES0__INSTANCE0.DEPANBLKGKANAN), INT_ENUM},
{&(RES0__INSTANCE0.ATASBAWAHKANAN), INT_ENUM},
{&(RES0__INSTANCE0.KIRIKANANKANAN), INT_ENUM},
{&(RES0__INSTANCE0.DEPANBLKGKIRI), INT_ENUM},
{&(RES0__INSTANCE0.ATASBAWAHKIRI), INT_ENUM},
{&(RES0__INSTANCE0.KIRIKANANKIRI), INT_ENUM},
{&(RES0__INSTANCE0.BCKIRINAIK1), INT_ENUM},
{&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON3.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON4.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON5.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON6.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON7.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON8.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON10.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON10.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON10.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON10.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON10.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON10.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON10.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON10.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON10.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON10.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON11.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON11.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON11.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON11.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON11.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON11.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON11.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON11.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON11.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON11.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON9.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON9.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON9.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON9.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON9.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON9.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON9.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON9.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON9.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON9.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON12.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON12.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON12.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON12.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON12.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON12.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON12.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON12.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON12.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON12.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON13.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON13.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON13.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON13.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON13.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON13.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON13.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON13.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON13.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON13.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON14.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON14.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON14.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON14.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON14.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON14.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON14.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON14.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON14.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON14.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON15.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON15.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON15.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON15.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON15.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON15.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON15.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON15.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON15.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON15.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON16.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON16.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON16.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON16.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON16.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON16.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON16.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON16.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON16.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON16.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON18.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON18.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON18.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON18.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON18.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON18.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON18.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON18.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON18.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON18.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON21.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON21.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON21.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON21.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON21.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON21.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON21.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON21.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON21.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON21.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON24.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON24.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON24.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON24.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON24.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON24.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON24.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON24.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON24.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON24.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON19.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON19.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON19.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON19.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON19.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON19.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON19.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON19.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON19.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON19.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON20.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON20.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON20.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON20.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON20.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON20.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON20.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON20.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON20.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON20.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON22.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON22.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON22.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON22.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON22.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON22.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON22.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON22.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON22.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON22.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON23.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON23.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON23.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON23.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON23.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON23.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON23.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON23.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON23.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON23.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE271_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE271_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE280_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE280_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE277_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE277_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE317_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE317_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE265_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE265_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE293_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE293_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE305_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE305_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE308_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE308_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE311_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE311_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE121_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE121_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE112_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE112_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE18_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE18_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE195_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE195_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE186_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE186_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE176_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE176_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE81_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE81_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE123_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE123_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE138_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE138_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE181_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE181_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE197_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE197_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE212_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE212_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE142_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE142_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE145_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE145_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE148_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE148_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE216_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE216_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE219_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE219_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE222_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOVE222_OUT), INT_ENUM}
};

static const dbgvardsc_index_t retain_list[] = {

};
static unsigned int retain_list_collect_cursor = 0;
static const unsigned int retain_list_size = sizeof(retain_list)/sizeof(dbgvardsc_index_t);

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    unsigned int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_desc_type dbgvardsc_t


#define __Unpack_case_t(TYPENAME)                                           \
        case TYPENAME##_ENUM :                                              \
            if(flags) *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;       \
            if(value_p) *value_p = &((__IEC_##TYPENAME##_t *)varp)->value;  \
		    if(size) *size = sizeof(TYPENAME);                              \
            break;

#define __Unpack_case_p(TYPENAME)                                           \
        case TYPENAME##_O_ENUM :                                            \
        case TYPENAME##_P_ENUM :                                            \
            if(flags) *flags = ((__IEC_##TYPENAME##_p *)varp)->flags;       \
            if(value_p) *value_p = ((__IEC_##TYPENAME##_p *)varp)->value;   \
		    if(size) *size = sizeof(TYPENAME);                              \
            break;

#define __Is_a_string(dsc) (dsc->type == STRING_ENUM)   ||\
                           (dsc->type == STRING_P_ENUM) ||\
                           (dsc->type == STRING_O_ENUM)

static int UnpackVar(__Unpack_desc_type *dsc, void **value_p, char *flags, size_t *size)
{
    void *varp = dsc->ptr;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        return 0; /* should never happen */
    }
    return 1;
}



void Remind(unsigned int offset, unsigned int count, void * p);

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
#ifndef TARGET_ONLINE_DEBUG_DISABLE
    trace_buffer_cursor = trace_buffer;
    trace_list_addvar_cursor = trace_list;
    trace_list_collect_cursor = trace_list;
    trace_buffer_state = BUFFER_EMPTY;

    force_buffer_cursor = force_buffer;
    force_list_addvar_cursor = force_list;
    force_list_apply_cursor = force_list;
#endif

    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
        static unsigned int retain_offset = 0;
        retain_list_collect_cursor = 0;

        /* iterate over retain list */
        while(retain_list_collect_cursor < retain_list_size){
            void *value_p = NULL;
            size_t size;
            char* next_cursor;

            dbgvardsc_t *dsc = &dbgvardsc[
                retain_list[retain_list_collect_cursor]];

            UnpackVar(dsc, &value_p, NULL, &size);

            printf("Reminding %d %ld \n", retain_list_collect_cursor, size);

            /* if buffer not full */
            Remind(retain_offset, size, value_p);
            /* increment cursor according size*/
            retain_offset += size;

            retain_list_collect_cursor++;
        }
    }else{
        char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
#ifndef TARGET_ONLINE_DEBUG_DISABLE
    trace_buffer_cursor = trace_buffer;
    InitiateDebugTransfer();
#endif    

    CleanupRetain();
}

void __retrieve_debug(void)
{
}

void Retain(unsigned int offset, unsigned int count, void * p);

/* Return size of all retain variables */
unsigned int GetRetainSize(void)
{
    unsigned int retain_size = 0;
    retain_list_collect_cursor = 0;

    /* iterate over retain list */
    while(retain_list_collect_cursor < retain_list_size){
        void *value_p = NULL;
        size_t size;
        char* next_cursor;

        dbgvardsc_t *dsc = &dbgvardsc[
            retain_list[retain_list_collect_cursor]];

        UnpackVar(dsc, &value_p, NULL, &size);

        retain_size += size;
        retain_list_collect_cursor++;
    }

    printf("Retain size %d \n", retain_size);
            
    return retain_size;
}


extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

#define __ReForceOutput_case_p(TYPENAME)                                                            \
        case TYPENAME##_P_ENUM :                                                                    \
        case TYPENAME##_O_ENUM :                                                                    \
            {                                                                                       \
                char *next_cursor = force_buffer_cursor + sizeof(TYPENAME);                         \
                if(next_cursor <= force_buffer_end ){                                               \
                    /* outputs real value must be systematically forced */                          \
                    if(vartype == TYPENAME##_O_ENUM)                                                \
                        /* overwrite value pointed by backup */                                     \
                        *((TYPENAME *)force_list_apply_cursor->value_pointer_backup) =  \
                            *((TYPENAME *)force_buffer_cursor);                                     \
                    /* inc force_buffer cursor */                                                   \
                    force_buffer_cursor = next_cursor;                                              \
                }else{                                                                              \
                    stop = 1;                                                                       \
                }                                                                                   \
            }                                                                                       \
            break;
void __publish_debug(void)
{
    InValidateRetainBuffer();
    
#ifndef TARGET_ONLINE_DEBUG_DISABLE 
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &trace_buffer_state,
            BUFFER_EMPTY,
            BUFFER_FULL);
            
        /* If buffer was free */
        if(latest_state == BUFFER_EMPTY)
        {
            int stop = 0;
            /* Reset force list cursor */
            force_list_apply_cursor = force_list;

            /* iterate over force list */
            while(!stop && force_list_apply_cursor < force_list_addvar_cursor){
                dbgvardsc_t *dsc = &dbgvardsc[
                    force_list_apply_cursor->dbgvardsc_index];
                void *varp = dsc->ptr;
                __IEC_types_enum vartype = dsc->type;
                switch(vartype){
                    __ANY(__ReForceOutput_case_p)
                default:
                    break;
                }
                force_list_apply_cursor++;                                                      \
            }

            /* Reset buffer cursor */
            trace_buffer_cursor = trace_buffer;
            /* Reset trace list cursor */
            trace_list_collect_cursor = trace_list;

            /* iterate over trace list */
            while(trace_list_collect_cursor < trace_list_addvar_cursor){
                void *value_p = NULL;
                size_t size;
                char* next_cursor;

                dbgvardsc_t *dsc = &dbgvardsc[
                    trace_list_collect_cursor->dbgvardsc_index];

                UnpackVar(dsc, &value_p, NULL, &size);

                /* copy visible variable to buffer */;
                if(__Is_a_string(dsc)){
                    /* optimization for strings */
                    /* assume NULL terminated strings */
                    size = ((STRING*)value_p)->len + 1;
                }

                /* compute next cursor positon.*/
                next_cursor = trace_buffer_cursor + size;
                /* check for buffer overflow */
                if(next_cursor < trace_buffer_end)
                    /* copy data to the buffer */
                    memcpy(trace_buffer_cursor, value_p, size);
                else
                    /* stop looping in case of overflow */
                    break;
                /* increment cursor according size*/
                trace_buffer_cursor = next_cursor;
                trace_list_collect_cursor++;
            }
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }
        LeaveDebugSection();
    }
#endif
    static unsigned int retain_offset = 0;
    /* when not debugging, do only retain */
    retain_list_collect_cursor = 0;

    /* iterate over retain list */
    while(retain_list_collect_cursor < retain_list_size){
        void *value_p = NULL;
        size_t size;
        char* next_cursor;

        dbgvardsc_t *dsc = &dbgvardsc[
            retain_list[retain_list_collect_cursor]];

        UnpackVar(dsc, &value_p, NULL, &size);

        /* if buffer not full */
        Retain(retain_offset, size, value_p);
        /* increment cursor according size*/
        retain_offset += size;

        retain_list_collect_cursor++;
    }
    ValidateRetainBuffer();
}

#ifndef TARGET_ONLINE_DEBUG_DISABLE

#define TRACE_LIST_OVERFLOW    1
#define FORCE_LIST_OVERFLOW    2
#define FORCE_BUFFER_OVERFLOW  3

#define __ForceVariable_case_t(TYPENAME)                                                \
        case TYPENAME##_ENUM :                                                          \
            /* add to force_list*/                                                      \
            force_list_addvar_cursor->dbgvardsc_index = idx;                            \
            ((__IEC_##TYPENAME##_t *)varp)->flags |= __IEC_FORCE_FLAG;                  \
            ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);               \
            break;
#define __ForceVariable_case_p(TYPENAME)                                                \
        case TYPENAME##_P_ENUM :                                                        \
        case TYPENAME##_O_ENUM :                                                        \
            {                                                                           \
                char *next_cursor = force_buffer_cursor + sizeof(TYPENAME);             \
                if(next_cursor <= force_buffer_end ){                                   \
                    /* add to force_list*/                                              \
                    force_list_addvar_cursor->dbgvardsc_index = idx;                    \
                    /* save pointer to backup */                                        \
                    force_list_addvar_cursor->value_pointer_backup =                    \
                        ((__IEC_##TYPENAME##_p *)varp)->value;                          \
                    /* store forced value in force_buffer */                            \
                    *((TYPENAME *)force_buffer_cursor) = *((TYPENAME *)force);          \
                    /* replace pointer with pointer to force_buffer */                  \
                    ((__IEC_##TYPENAME##_p *)varp)->value =                             \
                        (TYPENAME *)force_buffer_cursor;                                \
                    /* mark variable as forced */                                       \
                    ((__IEC_##TYPENAME##_p *)varp)->flags |= __IEC_FORCE_FLAG;          \
                    /* inc force_buffer cursor */                                       \
                    force_buffer_cursor = next_cursor;                                  \
                    /* outputs real value must be systematically forced */              \
                    if(vartype == TYPENAME##_O_ENUM)                                    \
                        *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
                } else {                                                                \
                    error_code = FORCE_BUFFER_OVERFLOW;                                 \
                    goto error_cleanup;                                                 \
                }                                                                       \
            }                                                                           \
            break;


void ResetDebugVariables(void);

int RegisterDebugVariable(dbgvardsc_index_t idx, void* force)
{
    int error_code = 0;
    if(idx < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        /* add to trace_list, inc trace_list_addvar_cursor*/
        if(trace_list_addvar_cursor <= trace_list_end){
            trace_list_addvar_cursor->dbgvardsc_index = idx;
            trace_list_addvar_cursor++;
        } else {
            error_code = TRACE_LIST_OVERFLOW;
            goto error_cleanup;
        }
        if(force){
            if(force_list_addvar_cursor <= force_list_end){
                dbgvardsc_t *dsc = &dbgvardsc[idx];
                void *varp = dsc->ptr;
                __IEC_types_enum vartype = dsc->type;

                switch(vartype){
                    __ANY(__ForceVariable_case_t)
                    __ANY(__ForceVariable_case_p)
                default:
                    break;
                }
                /* inc force_list cursor */
                force_list_addvar_cursor++;
            } else {
                error_code = FORCE_LIST_OVERFLOW;
                goto error_cleanup;
            }
        }
    }
    return 0;

error_cleanup:
    ResetDebugVariables();
    trace_buffer_state = BUFFER_EMPTY;
    return error_code;
    
}

#define ResetForcedVariable_case_t(TYPENAME)                                            \
        case TYPENAME##_ENUM :                                                          \
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~__IEC_FORCE_FLAG;                 \
            /* for local variable we don't restore original value */                    \
            /* that can be added if needed, but it was like that since ever */          \
            break;

#define ResetForcedVariable_case_p(TYPENAME)                                            \
        case TYPENAME##_P_ENUM :                                                        \
        case TYPENAME##_O_ENUM :                                                        \
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~__IEC_FORCE_FLAG;                 \
            /* restore backup to pointer */                                             \
            ((__IEC_##TYPENAME##_p *)varp)->value =                                     \
                force_list_apply_cursor->value_pointer_backup;                          \
            break;

void ResetDebugVariables(void)
{
    /* Reset trace list */
    trace_list_addvar_cursor = trace_list;

    force_list_apply_cursor = force_list;
    /* Restore forced variables */
    while(force_list_apply_cursor < force_list_addvar_cursor){
        dbgvardsc_t *dsc = &dbgvardsc[
            force_list_apply_cursor->dbgvardsc_index];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(ResetForcedVariable_case_t)
            __ANY(ResetForcedVariable_case_p)
        default:
            break;
        }
        /* inc force_list cursor */
        force_list_apply_cursor++;
    } /* else TODO: warn user about failure to force */ 

    /* Reset force list */
    force_list_addvar_cursor = force_list;
    /* Reset force buffer */
    force_buffer_cursor = force_buffer;
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &trace_buffer_state,
        BUFFER_FULL,
        BUFFER_EMPTY);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = trace_buffer_cursor - trace_buffer;
        *buffer = trace_buffer;
    }
    return wait_error;
}
#endif
#endif

