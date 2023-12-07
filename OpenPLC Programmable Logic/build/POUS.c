void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT1(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE271_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE271_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT2(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE280_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE280_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT3(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE277_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE277_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT4(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE317_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE317_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT5(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE265_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE265_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT6(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE293_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE293_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT7(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE305_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE305_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT8(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE308_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE308_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT9(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE311_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE311_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT10(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE121_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE121_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT11(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE112_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE112_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT12(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE18_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE18_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT13(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE195_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE195_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT14(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE186_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE186_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT15(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE176_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE176_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT16(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE81_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE81_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT17(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE123_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE123_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT18(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE138_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE138_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT19(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE181_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE181_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT20(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE197_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE197_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT21(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE212_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE212_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT22(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE142_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE142_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT23(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE145_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE145_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT24(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE148_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE148_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT25(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE216_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE216_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT26(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE219_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE219_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT27(BOOL EN,
  INT IN,
  PROJEK_MEKATRONIKA_KOMPLEKS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE222_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE222_ENO,,__TMP_ENO);
  return __res;
}

void PROJEK_MEKATRONIKA_KOMPLEKS_init__(PROJEK_MEKATRONIKA_KOMPLEKS *data__, BOOL retain) {
  __INIT_VAR(data__->SENSORTINGGI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRENDAH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPALLET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOADED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENTRYKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EXITKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENTRYKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EXITKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BERHENTIDARURAT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FACTORYBERJALAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PALLETSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPICKPLACEKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRENDAHKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORTINGGIKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPICKPLACEKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORSTOPPER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENTRYCONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOAD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UNLOAD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->KEKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->KEKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYORKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYORKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EMITTER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REMOVERKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REMOVERKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAMPUSTART,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAMPURESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAMPUSTOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYORKANANBELOKKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYORPICKPLACEKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AMBILKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCKANANNAIK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCKIRINAIK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCKIRI1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCPALLETIZER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHERKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AMBILKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUTERKIRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOPPER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUTOMODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESETMODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MANUALMODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUNNINGMODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STARTLATCH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PALLETSENSORMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRENDAHMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORTINGGIMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRENDAHRESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORTINGGIRESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRENDAHKANANMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORTINGGIKANANMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PINDAHBOXKANANMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BALIKTEMPATKANANMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRESETKANAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PINDAHBOXKIRIMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BALIKTEMPATKIRIMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEPASKIRIMEM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHERRESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DEPANBLKGKANAN,0,retain)
  __INIT_VAR(data__->ATASBAWAHKANAN,0,retain)
  __INIT_VAR(data__->KIRIKANANKANAN,0,retain)
  __INIT_VAR(data__->DEPANBLKGKIRI,0,retain)
  __INIT_VAR(data__->ATASBAWAHKIRI,0,retain)
  __INIT_VAR(data__->KIRIKANANKIRI,0,retain)
  __INIT_VAR(data__->BCKIRINAIK1,0,retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
  TON_init__(&data__->TON6,retain);
  TON_init__(&data__->TON7,retain);
  TON_init__(&data__->TON8,retain);
  TON_init__(&data__->TON10,retain);
  TON_init__(&data__->TON11,retain);
  TON_init__(&data__->TON9,retain);
  TON_init__(&data__->TON12,retain);
  TON_init__(&data__->TON13,retain);
  TON_init__(&data__->TON14,retain);
  TON_init__(&data__->TON15,retain);
  TON_init__(&data__->TON16,retain);
  TON_init__(&data__->TON18,retain);
  TON_init__(&data__->TON21,retain);
  TON_init__(&data__->TON24,retain);
  TON_init__(&data__->TON19,retain);
  TON_init__(&data__->TON20,retain);
  TON_init__(&data__->TON22,retain);
  TON_init__(&data__->TON23,retain);
  __INIT_VAR(data__->_TMP_MOVE271_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE271_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE280_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE280_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE277_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE277_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE317_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE317_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE265_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE265_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE293_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE293_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE305_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE305_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE308_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE308_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE311_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE311_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE121_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE121_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE112_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE112_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE18_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE18_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE195_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE195_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE186_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE186_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE176_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE176_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE81_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE81_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE123_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE123_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE138_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE138_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE181_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE181_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE197_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE197_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE212_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE212_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE142_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE142_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE145_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE145_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE148_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE148_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE216_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE216_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE219_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE219_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE222_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE222_OUT,0,retain)
}

// Code part
void PROJEK_MEKATRONIKA_KOMPLEKS_body__(PROJEK_MEKATRONIKA_KOMPLEKS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,AUTOMODE,,((!(__GET_VAR(data__->MANUALMODE,)) && __GET_VAR(data__->AUTO,)) && __GET_VAR(data__->FACTORYBERJALAN,)));
  __SET_VAR(data__->,ENTRYCONVEYOR,,((!(__GET_VAR(data__->LOADED,)) && !(__GET_VAR(data__->PALLETSENSORMEM,))) && __GET_VAR(data__->RUNNINGMODE,)));
  __SET_VAR(data__->,MANUALMODE,,((!(__GET_VAR(data__->AUTOMODE,)) && __GET_VAR(data__->MANUAL,)) && __GET_VAR(data__->FACTORYBERJALAN,)));
  __SET_VAR(data__->,EMITTER,,((!(__GET_VAR(data__->LOADED,)) && !(__GET_VAR(data__->PALLETSENSORMEM,))) && __GET_VAR(data__->RUNNINGMODE,)));
  if (__GET_VAR(data__->CONVEYORKIRI,)) {
    __SET_VAR(data__->,BCKIRI1,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,RESETMODE,,(__GET_VAR(data__->RESET,) && (__GET_VAR(data__->MANUALMODE,) || __GET_VAR(data__->RESETMODE,))));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->SENSORPALLET,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,PALLETSENSORMEM,,__GET_VAR(data__->TON0.Q,));
  if ((__GET_VAR(data__->STOP,) && ((!(__GET_VAR(data__->ENTRYKANAN,)) && __GET_VAR(data__->SENSORTINGGIMEM,)) || __GET_VAR(data__->CONVEYORKANAN,)))) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,RUNNINGMODE,,(__GET_VAR(data__->STARTLATCH,) && (__GET_VAR(data__->AUTOMODE,) || __GET_VAR(data__->MANUALMODE,))));
  __SET_VAR(data__->,LOAD,,(!(__GET_VAR(data__->LOADED,)) && (__GET_VAR(data__->LOAD,) || __GET_VAR(data__->SENSORPALLET,))));
  if ((__GET_VAR(data__->STOP,) && ((!(__GET_VAR(data__->ENTRYKIRI,)) && __GET_VAR(data__->SENSORRENDAHMEM,)) || __GET_VAR(data__->CONVEYORKIRI,)))) {
    __SET_VAR(data__->,CONVEYORKIRI,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,STARTLATCH,,(__GET_VAR(data__->STOP,) && (__GET_VAR(data__->START,) || __GET_VAR(data__->STARTLATCH,))));
  __SET_VAR(data__->,KEKANAN,,(!(__GET_VAR(data__->SENSORPALLET,)) && ((__GET_VAR(data__->SENSORTINGGIMEM,) && __GET_VAR(data__->LOADED,)) || !(__GET_VAR(data__->ENTRYKANAN,)))));
  __SET_VAR(data__->,_TMP_MOVE271_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT1(
    (BOOL)__GET_VAR(data__->SENSORPICKPLACEKIRI,),
    (INT)200,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE271_ENO,)) {
    __SET_VAR(data__->,BCKIRI1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE271_ENO,)) {
    __SET_VAR(data__->,BALIKTEMPATKIRIMEM,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,_TMP_MOVE280_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT2(
    (BOOL)__GET_VAR(data__->_TMP_MOVE271_ENO,),
    (INT)230,
    data__));
  __SET_VAR(data__->TON18.,IN,,__GET_VAR(data__->_TMP_MOVE280_ENO,));
  __SET_VAR(data__->TON18.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON18);
  __SET_VAR(data__->,_TMP_MOVE277_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT3(
    (BOOL)__GET_VAR(data__->TON18.Q,),
    (INT)980,
    data__));
  __SET_VAR(data__->TON24.,IN,,__GET_VAR(data__->_TMP_MOVE277_ENO,));
  __SET_VAR(data__->TON24.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON24);
  if (__GET_VAR(data__->TON24.Q,)) {
    __SET_VAR(data__->,AMBILKIRI,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON24.Q,)) {
    __SET_VAR(data__->,PINDAHBOXKIRIMEM,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,KEKIRI,,(!(__GET_VAR(data__->SENSORPALLET,)) && ((__GET_VAR(data__->SENSORRENDAHMEM,) && __GET_VAR(data__->LOADED,)) || !(__GET_VAR(data__->ENTRYKIRI,)))));
  if (__GET_VAR(data__->_TMP_MOVE271_ENO,)) {
    __SET_VAR(data__->,DEPANBLKGKIRI,,__GET_VAR(data__->_TMP_MOVE271_OUT,));
  };
  __SET_VAR(data__->,RUNNINGMODE,,((__GET_VAR(data__->STOP,) && __GET_VAR(data__->BERHENTIDARURAT,)) && __GET_VAR(data__->STARTLATCH,)));
  if (__GET_VAR(data__->_TMP_MOVE277_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKIRI,,__GET_VAR(data__->_TMP_MOVE277_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE280_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKIRI,,__GET_VAR(data__->_TMP_MOVE280_OUT,));
  };
  __SET_VAR(data__->TON23.,IN,,__GET_VAR(data__->PINDAHBOXKIRIMEM,));
  __SET_VAR(data__->TON23.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON23);
  __SET_VAR(data__->,_TMP_MOVE317_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT4(
    (BOOL)__GET_VAR(data__->TON23.Q,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE317_ENO,)) {
    __SET_VAR(data__->,PUSHERRESET,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON19.,IN,,__GET_VAR(data__->_TMP_MOVE317_ENO,));
  __SET_VAR(data__->TON19.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON19);
  __SET_VAR(data__->,_TMP_MOVE265_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT5(
    (BOOL)__GET_VAR(data__->TON19.Q,),
    (INT)910,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE265_ENO,)) {
    __SET_VAR(data__->,BCKIRI1,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE265_ENO,)) {
    __SET_VAR(data__->,REMOVERKIRI,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE265_ENO,)) {
    __SET_VAR(data__->,LEPASKIRIMEM,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,LAMPUSTART,,__GET_VAR(data__->RUNNINGMODE,));
  __SET_VAR(data__->,SENSORRENDAHMEM,,(!(__GET_VAR(data__->SENSORRENDAHRESET,)) && ((!(__GET_VAR(data__->SENSORTINGGI,)) && __GET_VAR(data__->SENSORRENDAH,)) || __GET_VAR(data__->SENSORRENDAHMEM,))));
  __SET_VAR(data__->,SENSORRENDAHRESET,,(!(__GET_VAR(data__->SENSORPALLET,)) && (!(__GET_VAR(data__->ENTRYKIRI,)) || __GET_VAR(data__->SENSORRENDAHRESET,))));
  if (__GET_VAR(data__->_TMP_MOVE317_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKIRI,,__GET_VAR(data__->_TMP_MOVE317_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE265_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKIRI,,__GET_VAR(data__->_TMP_MOVE265_OUT,));
  };
  __SET_VAR(data__->,LAMPUSTOP,,!(__GET_VAR(data__->RUNNINGMODE,)));
  __SET_VAR(data__->TON20.,IN,,__GET_VAR(data__->LEPASKIRIMEM,));
  __SET_VAR(data__->TON20.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON20);
  __SET_VAR(data__->,_TMP_MOVE293_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT6(
    (BOOL)__GET_VAR(data__->TON20.Q,),
    (INT)1000,
    data__));
  __SET_VAR(data__->TON22.,IN,,__GET_VAR(data__->_TMP_MOVE293_ENO,));
  __SET_VAR(data__->TON22.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON22);
  if (__GET_VAR(data__->TON22.Q,)) {
    __SET_VAR(data__->,AMBILKIRI,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON22.Q,)) {
    __SET_VAR(data__->,BALIKTEMPATKIRIMEM,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON22.Q,)) {
    __SET_VAR(data__->,PINDAHBOXKIRIMEM,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,LAMPURESET,,__GET_VAR(data__->RESETMODE,));
  __SET_VAR(data__->,SENSORTINGGIMEM,,(!(__GET_VAR(data__->SENSORTINGGIRESET,)) && ((__GET_VAR(data__->SENSORTINGGI,) && __GET_VAR(data__->SENSORRENDAH,)) || __GET_VAR(data__->SENSORTINGGIMEM,))));
  __SET_VAR(data__->,SENSORTINGGIRESET,,(!(__GET_VAR(data__->SENSORPALLET,)) && (!(__GET_VAR(data__->ENTRYKANAN,)) || __GET_VAR(data__->SENSORTINGGIRESET,))));
  if (__GET_VAR(data__->_TMP_MOVE293_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKIRI,,__GET_VAR(data__->_TMP_MOVE293_OUT,));
  };
  __SET_VAR(data__->TON21.,IN,,__GET_VAR(data__->BALIKTEMPATKIRIMEM,));
  __SET_VAR(data__->TON21.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON21);
  __SET_VAR(data__->,_TMP_MOVE305_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT7(
    (BOOL)__GET_VAR(data__->TON21.Q,),
    (INT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE308_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT8(
    (BOOL)__GET_VAR(data__->_TMP_MOVE305_ENO,),
    (INT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE311_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT9(
    (BOOL)__GET_VAR(data__->_TMP_MOVE308_ENO,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE311_ENO,)) {
    __SET_VAR(data__->,PINDAHBOXKIRIMEM,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE311_ENO,)) {
    __SET_VAR(data__->,BCPALLETIZER,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE311_ENO,)) {
    __SET_VAR(data__->,LEPASKIRIMEM,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,SENSORRENDAHKANANMEM,,(!(__GET_VAR(data__->SENSORRESETKANAN,)) && ((!(__GET_VAR(data__->SENSORTINGGIKANAN,)) && __GET_VAR(data__->SENSORRENDAHKANAN,)) || __GET_VAR(data__->SENSORRENDAHKANANMEM,))));
  if (__GET_VAR(data__->_TMP_MOVE305_ENO,)) {
    __SET_VAR(data__->,DEPANBLKGKIRI,,__GET_VAR(data__->_TMP_MOVE305_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE308_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKIRI,,__GET_VAR(data__->_TMP_MOVE308_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE311_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKIRI,,__GET_VAR(data__->_TMP_MOVE311_OUT,));
  };
  __SET_VAR(data__->TON6.,IN,,__GET_VAR(data__->SENSORPICKPLACEKANAN,));
  __SET_VAR(data__->TON6.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TON_body__(&data__->TON6);
  __SET_VAR(data__->,SENSORRESETKANAN,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->,SENSORTINGGIKANANMEM,,(!(__GET_VAR(data__->SENSORRESETKANAN,)) && ((__GET_VAR(data__->SENSORTINGGIKANAN,) && __GET_VAR(data__->SENSORRENDAHKANAN,)) || __GET_VAR(data__->SENSORTINGGIKANANMEM,))));
  __SET_VAR(data__->TON1.,IN,,!(__GET_VAR(data__->EXITKANAN,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_VAR(data__->,CONVEYORKANANBELOKKIRI,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,_TMP_MOVE121_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT10(
    (BOOL)(__GET_VAR(data__->SENSORTINGGIKANANMEM,) && __GET_VAR(data__->SENSORPICKPLACEKANAN,)),
    (INT)270,
    data__));
  __SET_VAR(data__->,_TMP_MOVE112_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT11(
    (BOOL)__GET_VAR(data__->_TMP_MOVE121_ENO,),
    (INT)200,
    data__));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->_TMP_MOVE112_ENO,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,_TMP_MOVE18_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT12(
    (BOOL)__GET_VAR(data__->TON2.Q,),
    (INT)795,
    data__));
  __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->_TMP_MOVE18_ENO,));
  __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON3);
  if (__GET_VAR(data__->TON3.Q,)) {
    __SET_VAR(data__->,AMBILKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON3.Q,)) {
    __SET_VAR(data__->,PINDAHBOXKANANMEM,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,_TMP_MOVE195_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT13(
    (BOOL)(__GET_VAR(data__->SENSORRENDAHKANANMEM,) && __GET_VAR(data__->SENSORPICKPLACEKANAN,)),
    (INT)270,
    data__));
  __SET_VAR(data__->,_TMP_MOVE186_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT14(
    (BOOL)__GET_VAR(data__->_TMP_MOVE195_ENO,),
    (INT)200,
    data__));
  __SET_VAR(data__->TON10.,IN,,__GET_VAR(data__->_TMP_MOVE186_ENO,));
  __SET_VAR(data__->TON10.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON10);
  __SET_VAR(data__->,_TMP_MOVE176_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT15(
    (BOOL)__GET_VAR(data__->TON10.Q,),
    (INT)10000,
    data__));
  __SET_VAR(data__->TON7.,IN,,__GET_VAR(data__->_TMP_MOVE176_ENO,));
  __SET_VAR(data__->TON7.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON7);
  if (__GET_VAR(data__->TON7.Q,)) {
    __SET_VAR(data__->,AMBILKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON7.Q,)) {
    __SET_VAR(data__->,PINDAHBOXKANANMEM,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE112_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKANAN,,__GET_VAR(data__->_TMP_MOVE112_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE18_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE18_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE186_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKANAN,,__GET_VAR(data__->_TMP_MOVE186_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE176_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE176_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE121_ENO,)) {
    __SET_VAR(data__->,DEPANBLKGKANAN,,__GET_VAR(data__->_TMP_MOVE121_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE195_ENO,)) {
    __SET_VAR(data__->,DEPANBLKGKANAN,,__GET_VAR(data__->_TMP_MOVE195_OUT,));
  };
  __SET_VAR(data__->TON4.,IN,,__GET_VAR(data__->PINDAHBOXKANANMEM,));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON4);
  __SET_VAR(data__->,_TMP_MOVE81_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT16(
    (BOOL)__GET_VAR(data__->TON4.Q,),
    (INT)0,
    data__));
  __SET_VAR(data__->TON12.,IN,,__GET_VAR(data__->_TMP_MOVE81_ENO,));
  __SET_VAR(data__->TON12.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TON_body__(&data__->TON12);
  __SET_VAR(data__->,_TMP_MOVE123_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT17(
    (BOOL)__GET_VAR(data__->TON12.Q,),
    (INT)800,
    data__));
  __SET_VAR(data__->TON5.,IN,,__GET_VAR(data__->_TMP_MOVE123_ENO,));
  __SET_VAR(data__->TON5.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON5);
  __SET_VAR(data__->,_TMP_MOVE138_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT18(
    (BOOL)__GET_VAR(data__->TON5.Q,),
    (INT)280,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE138_ENO,)) {
    __SET_VAR(data__->,AMBILKANAN,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE138_ENO,)) {
    __SET_VAR(data__->,PINDAHBOXKANANMEM,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE138_ENO,)) {
    __SET_VAR(data__->,BALIKTEMPATKANANMEM,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON8.,IN,,__GET_VAR(data__->PINDAHBOXKANANMEM,));
  __SET_VAR(data__->TON8.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON8);
  __SET_VAR(data__->,_TMP_MOVE181_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT19(
    (BOOL)__GET_VAR(data__->TON8.Q,),
    (INT)0,
    data__));
  __SET_VAR(data__->TON9.,IN,,__GET_VAR(data__->_TMP_MOVE181_ENO,));
  __SET_VAR(data__->TON9.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON9);
  __SET_VAR(data__->,_TMP_MOVE197_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT20(
    (BOOL)__GET_VAR(data__->TON9.Q,),
    (INT)800,
    data__));
  __SET_VAR(data__->TON11.,IN,,__GET_VAR(data__->_TMP_MOVE197_ENO,));
  __SET_VAR(data__->TON11.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON11);
  __SET_VAR(data__->,_TMP_MOVE212_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT21(
    (BOOL)__GET_VAR(data__->TON11.Q,),
    (INT)280,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE212_ENO,)) {
    __SET_VAR(data__->,AMBILKANAN,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE212_ENO,)) {
    __SET_VAR(data__->,PINDAHBOXKANANMEM,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE212_ENO,)) {
    __SET_VAR(data__->,BALIKTEMPATKANANMEM,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE123_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKANAN,,__GET_VAR(data__->_TMP_MOVE123_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE197_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKANAN,,__GET_VAR(data__->_TMP_MOVE197_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE138_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE138_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE212_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE212_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE81_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE81_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE181_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE181_OUT,));
  };
  __SET_VAR(data__->TON15.,IN,,__GET_VAR(data__->BALIKTEMPATKANANMEM,));
  __SET_VAR(data__->TON15.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON15);
  __SET_VAR(data__->,_TMP_MOVE142_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT22(
    (BOOL)__GET_VAR(data__->TON15.Q,),
    (INT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE145_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT23(
    (BOOL)__GET_VAR(data__->_TMP_MOVE142_ENO,),
    (INT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE148_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT24(
    (BOOL)__GET_VAR(data__->_TMP_MOVE145_ENO,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE148_ENO,)) {
    __SET_VAR(data__->,BALIKTEMPATKANANMEM,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE148_ENO,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE148_ENO,)) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON16.,IN,,__GET_VAR(data__->BALIKTEMPATKANANMEM,));
  __SET_VAR(data__->TON16.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON16);
  __SET_VAR(data__->,_TMP_MOVE216_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT25(
    (BOOL)__GET_VAR(data__->TON16.Q,),
    (INT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE219_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT26(
    (BOOL)__GET_VAR(data__->_TMP_MOVE216_ENO,),
    (INT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE222_OUT,,__PROJEK_MEKATRONIKA_KOMPLEKS_MOVE__INT__INT27(
    (BOOL)__GET_VAR(data__->_TMP_MOVE219_ENO,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE222_ENO,)) {
    __SET_VAR(data__->,BALIKTEMPATKANANMEM,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->_TMP_MOVE222_ENO,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE222_ENO,)) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_MOVE142_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE142_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE145_ENO,)) {
    __SET_VAR(data__->,DEPANBLKGKANAN,,__GET_VAR(data__->_TMP_MOVE145_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE148_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKANAN,,__GET_VAR(data__->_TMP_MOVE148_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE216_ENO,)) {
    __SET_VAR(data__->,ATASBAWAHKANAN,,__GET_VAR(data__->_TMP_MOVE216_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE219_ENO,)) {
    __SET_VAR(data__->,DEPANBLKGKANAN,,__GET_VAR(data__->_TMP_MOVE219_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE222_ENO,)) {
    __SET_VAR(data__->,KIRIKANANKANAN,,__GET_VAR(data__->_TMP_MOVE222_OUT,));
  };
  if (__GET_VAR(data__->SENSORPICKPLACEKANAN,)) {
    __SET_VAR(data__->,CONVEYORKANANBELOKKIRI,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SENSORPICKPLACEKANAN,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SENSORPICKPLACEKANAN,)) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON13.,IN,,__GET_VAR(data__->SENSORPICKPLACEKANAN,));
  __SET_VAR(data__->TON13.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON13);
  if (__GET_VAR(data__->TON13.Q,)) {
    __SET_VAR(data__->,CONVEYORKANANBELOKKIRI,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON13.Q,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON13.Q,)) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->SENSORPICKPLACEKANAN,)) {
    __SET_VAR(data__->,CONVEYORKANANBELOKKIRI,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SENSORPICKPLACEKANAN,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SENSORPICKPLACEKANAN,)) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON14.,IN,,__GET_VAR(data__->SENSORPICKPLACEKANAN,));
  __SET_VAR(data__->TON14.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON14);
  if (__GET_VAR(data__->TON14.Q,)) {
    __SET_VAR(data__->,CONVEYORKANANBELOKKIRI,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON14.Q,)) {
    __SET_VAR(data__->,CONVEYORPICKPLACEKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON14.Q,)) {
    __SET_VAR(data__->,CONVEYORKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->BALIKTEMPATKANANMEM,)) {
    __SET_VAR(data__->,BCKANAN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->BALIKTEMPATKANANMEM,)) {
    __SET_VAR(data__->,BCKANANNAIK,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // PROJEK_MEKATRONIKA_KOMPLEKS_body__() 





