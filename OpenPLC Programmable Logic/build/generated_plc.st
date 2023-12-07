PROGRAM projek_mekatronika_kompleks
  VAR
    SensorTinggi AT %IX100.0 : BOOL;
    SensorRendah AT %IX100.1 : BOOL;
    SensorPallet AT %IX100.2 : BOOL;
    Loaded AT %IX100.3 : BOOL;
    EntryKiri AT %IX100.4 : BOOL;
    ExitKiri AT %IX100.5 : BOOL;
    EntryKanan AT %IX100.6 : BOOL;
    ExitKanan AT %IX100.7 : BOOL;
    BerhentiDarurat AT %IX100.8 : BOOL;
    Start AT %IX100.9 : BOOL;
    Reset AT %IX100.10 : BOOL;
    Stop AT %IX100.11 : BOOL;
    FactoryBerjalan AT %IX100.12 : BOOL;
    Manual AT %IX100.13 : BOOL;
    Auto AT %IX100.14 : BOOL;
    PalletSensor AT %IX100.15 : BOOL;
    SensorPickPlaceKanan AT %IX100.16 : BOOL;
    SensorRendahKANAN AT %IX100.17 : BOOL;
    SensorTinggiKANAN AT %IX100.18 : BOOL;
    SensorPickPlaceKIRI AT %IX100.19 : BOOL;
    SensorStopper AT %IX100.20 : BOOL;
    EntryConveyor AT %QX100.0 : BOOL;
    Load AT %QX100.1 : BOOL;
    Unload AT %QX100.2 : BOOL;
    KeKiri AT %QX100.3 : BOOL;
    KeKanan AT %QX100.4 : BOOL;
    ConveyorKiri AT %QX100.5 : BOOL;
    ConveyorKanan AT %QX100.6 : BOOL;
    Emitter AT %QX100.7 : BOOL;
    RemoverKiri AT %QX100.8 : BOOL;
    RemoverKanan AT %QX100.9 : BOOL;
    LampuStart AT %QX100.10 : BOOL;
    LampuReset AT %QX100.11 : BOOL;
    LampuStop AT %QX100.12 : BOOL;
    ConveyorKananBelokKiri AT %QX100.13 : BOOL;
    ConveyorPickPlaceKanan AT %QX100.14 : BOOL;
    AmbilKANAN AT %QX100.15 : BOOL;
    BCKanan AT %QX100.16 : BOOL;
    BCKananNaik AT %QX100.17 : BOOL;
    BCKiriNaik AT %QX100.18 : BOOL;
    BCKiri1 AT %QX100.19 : BOOL;
    BCPalletizer AT %QX100.20 : BOOL;
    PusherKIRI AT %QX100.21 : BOOL;
    AmbilKIRI AT %QX100.22 : BOOL;
    MuterKIRI AT %QX100.23 : BOOL;
    Stopper AT %QX100.24 : BOOL;
    AutoMode AT %IX0.0 : BOOL;
    ResetMode AT %IX0.1 : BOOL;
    ManualMode AT %IX0.2 : BOOL;
    RunningMode AT %IX0.3 : BOOL;
    StartLatch AT %IX0.4 : BOOL;
    PalletSensorMem AT %IX0.5 : BOOL;
    SensorRendahMem AT %IX0.6 : BOOL;
    SensorTinggiMem AT %IX0.7 : BOOL;
    SensorRendahReset AT %IX0.8 : BOOL;
    SensorTinggiReset AT %IX0.9 : BOOL;
    SensorRendahKANANMem AT %IX0.10 : BOOL;
    SensorTinggiKANANMem AT %IX0.11 : BOOL;
    PindahBoxKANANMem AT %QX0.0 : BOOL;
    BalikTempatKANANMem AT %QX0.1 : BOOL;
    SensorResetKANAN AT %QX0.2 : BOOL;
    PindahBoxKIRIMem AT %QX0.3 : BOOL;
    BalikTempatKIRIMem AT %QX0.4 : BOOL;
    LepasKiriMem AT %QX0.5 : BOOL;
    PusherReset AT %QX0.6 : BOOL;
    DepanBlkgKANAN AT %QW100 : INT;
    AtasBawahKANAN AT %QW101 : INT;
    KiriKananKANAN AT %QW102 : INT;
    DepanBlkgKIRI AT %QW103 : INT;
    AtasBawahKIRI AT %QW104 : INT;
    KiriKananKIRI AT %QW105 : INT;
    BCKiriNaik1 AT %QW106 : INT;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
    TON2 : TON;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
    TON6 : TON;
    TON7 : TON;
    TON8 : TON;
    TON10 : TON;
    TON11 : TON;
    TON9 : TON;
    TON12 : TON;
    TON13 : TON;
    TON14 : TON;
    TON15 : TON;
    TON16 : TON;
    TON18 : TON;
    TON21 : TON;
    TON24 : TON;
    TON19 : TON;
    TON20 : TON;
    TON22 : TON;
    TON23 : TON;
    _TMP_MOVE271_ENO : BOOL;
    _TMP_MOVE271_OUT : INT;
    _TMP_MOVE280_ENO : BOOL;
    _TMP_MOVE280_OUT : INT;
    _TMP_MOVE277_ENO : BOOL;
    _TMP_MOVE277_OUT : INT;
    _TMP_MOVE317_ENO : BOOL;
    _TMP_MOVE317_OUT : INT;
    _TMP_MOVE265_ENO : BOOL;
    _TMP_MOVE265_OUT : INT;
    _TMP_MOVE293_ENO : BOOL;
    _TMP_MOVE293_OUT : INT;
    _TMP_MOVE305_ENO : BOOL;
    _TMP_MOVE305_OUT : INT;
    _TMP_MOVE308_ENO : BOOL;
    _TMP_MOVE308_OUT : INT;
    _TMP_MOVE311_ENO : BOOL;
    _TMP_MOVE311_OUT : INT;
    _TMP_MOVE121_ENO : BOOL;
    _TMP_MOVE121_OUT : INT;
    _TMP_MOVE112_ENO : BOOL;
    _TMP_MOVE112_OUT : INT;
    _TMP_MOVE18_ENO : BOOL;
    _TMP_MOVE18_OUT : INT;
    _TMP_MOVE195_ENO : BOOL;
    _TMP_MOVE195_OUT : INT;
    _TMP_MOVE186_ENO : BOOL;
    _TMP_MOVE186_OUT : INT;
    _TMP_MOVE176_ENO : BOOL;
    _TMP_MOVE176_OUT : INT;
    _TMP_MOVE81_ENO : BOOL;
    _TMP_MOVE81_OUT : INT;
    _TMP_MOVE123_ENO : BOOL;
    _TMP_MOVE123_OUT : INT;
    _TMP_MOVE138_ENO : BOOL;
    _TMP_MOVE138_OUT : INT;
    _TMP_MOVE181_ENO : BOOL;
    _TMP_MOVE181_OUT : INT;
    _TMP_MOVE197_ENO : BOOL;
    _TMP_MOVE197_OUT : INT;
    _TMP_MOVE212_ENO : BOOL;
    _TMP_MOVE212_OUT : INT;
    _TMP_MOVE142_ENO : BOOL;
    _TMP_MOVE142_OUT : INT;
    _TMP_MOVE145_ENO : BOOL;
    _TMP_MOVE145_OUT : INT;
    _TMP_MOVE148_ENO : BOOL;
    _TMP_MOVE148_OUT : INT;
    _TMP_MOVE216_ENO : BOOL;
    _TMP_MOVE216_OUT : INT;
    _TMP_MOVE219_ENO : BOOL;
    _TMP_MOVE219_OUT : INT;
    _TMP_MOVE222_ENO : BOOL;
    _TMP_MOVE222_OUT : INT;
  END_VAR

  AutoMode := NOT(ManualMode) AND Auto AND FactoryBerjalan;
  EntryConveyor := NOT(Loaded) AND NOT(PalletSensorMem) AND RunningMode;
  ManualMode := NOT(AutoMode) AND Manual AND FactoryBerjalan;
  Emitter := NOT(Loaded) AND NOT(PalletSensorMem) AND RunningMode;
  IF ConveyorKiri THEN
    BCKiri1 := TRUE; (*set*)
  END_IF;
  ResetMode := Reset AND (ManualMode OR ResetMode);
  TON0(IN := SensorPallet, PT := T#1000ms);
  PalletSensorMem := TON0.Q;
  IF Stop AND (NOT(EntryKanan) AND SensorTinggiMem OR ConveyorKanan) THEN
    ConveyorKanan := TRUE; (*set*)
  END_IF;
  RunningMode := StartLatch AND (AutoMode OR ManualMode);
  Load := NOT(Loaded) AND (Load OR SensorPallet);
  IF Stop AND (NOT(EntryKiri) AND SensorRendahMem OR ConveyorKiri) THEN
    ConveyorKiri := TRUE; (*set*)
  END_IF;
  StartLatch := Stop AND (Start OR StartLatch);
  KeKanan := NOT(SensorPallet) AND (SensorTinggiMem AND Loaded OR NOT(EntryKanan));
  _TMP_MOVE271_OUT := MOVE(EN := SensorPickPlaceKIRI, IN := 200, ENO => _TMP_MOVE271_ENO);
  IF _TMP_MOVE271_ENO THEN
    BCKiri1 := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE271_ENO THEN
    BalikTempatKIRIMem := FALSE; (*reset*)
  END_IF;
  _TMP_MOVE280_OUT := MOVE(EN := _TMP_MOVE271_ENO, IN := 230, ENO => _TMP_MOVE280_ENO);
  TON18(IN := _TMP_MOVE280_ENO, PT := T#1000ms);
  _TMP_MOVE277_OUT := MOVE(EN := TON18.Q, IN := 980, ENO => _TMP_MOVE277_ENO);
  TON24(IN := _TMP_MOVE277_ENO, PT := T#500ms);
  IF TON24.Q THEN
    AmbilKIRI := TRUE; (*set*)
  END_IF;
  IF TON24.Q THEN
    PindahBoxKIRIMem := TRUE; (*set*)
  END_IF;
  KeKiri := NOT(SensorPallet) AND (SensorRendahMem AND Loaded OR NOT(EntryKiri));
  IF _TMP_MOVE271_ENO THEN
      DepanBlkgKIRI := _TMP_MOVE271_OUT;
  END_IF;
  RunningMode := Stop AND BerhentiDarurat AND StartLatch;
  IF _TMP_MOVE277_ENO THEN
      AtasBawahKIRI := _TMP_MOVE277_OUT;
  END_IF;
  IF _TMP_MOVE280_ENO THEN
      KiriKananKIRI := _TMP_MOVE280_OUT;
  END_IF;
  TON23(IN := PindahBoxKIRIMem, PT := T#1000ms);
  _TMP_MOVE317_OUT := MOVE(EN := TON23.Q, IN := 0, ENO => _TMP_MOVE317_ENO);
  IF _TMP_MOVE317_ENO THEN
    PusherReset := FALSE; (*reset*)
  END_IF;
  TON19(IN := _TMP_MOVE317_ENO, PT := T#1000ms);
  _TMP_MOVE265_OUT := MOVE(EN := TON19.Q, IN := 910, ENO => _TMP_MOVE265_ENO);
  IF _TMP_MOVE265_ENO THEN
    BCKiri1 := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE265_ENO THEN
    RemoverKiri := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE265_ENO THEN
    LepasKiriMem := TRUE; (*set*)
  END_IF;
  LampuStart := RunningMode;
  SensorRendahMem := NOT(SensorRendahReset) AND (NOT(SensorTinggi) AND SensorRendah OR SensorRendahMem);
  SensorRendahReset := NOT(SensorPallet) AND (NOT(EntryKiri) OR SensorRendahReset);
  IF _TMP_MOVE317_ENO THEN
      AtasBawahKIRI := _TMP_MOVE317_OUT;
  END_IF;
  IF _TMP_MOVE265_ENO THEN
      KiriKananKIRI := _TMP_MOVE265_OUT;
  END_IF;
  LampuStop := NOT(RunningMode);
  TON20(IN := LepasKiriMem, PT := T#1000ms);
  _TMP_MOVE293_OUT := MOVE(EN := TON20.Q, IN := 1000, ENO => _TMP_MOVE293_ENO);
  TON22(IN := _TMP_MOVE293_ENO, PT := T#500ms);
  IF TON22.Q THEN
    AmbilKIRI := FALSE; (*reset*)
  END_IF;
  IF TON22.Q THEN
    BalikTempatKIRIMem := TRUE; (*set*)
  END_IF;
  IF TON22.Q THEN
    PindahBoxKIRIMem := FALSE; (*reset*)
  END_IF;
  LampuReset := ResetMode;
  SensorTinggiMem := NOT(SensorTinggiReset) AND (SensorTinggi AND SensorRendah OR SensorTinggiMem);
  SensorTinggiReset := NOT(SensorPallet) AND (NOT(EntryKanan) OR SensorTinggiReset);
  IF _TMP_MOVE293_ENO THEN
      AtasBawahKIRI := _TMP_MOVE293_OUT;
  END_IF;
  TON21(IN := BalikTempatKIRIMem, PT := T#1000ms);
  _TMP_MOVE305_OUT := MOVE(EN := TON21.Q, IN := 0, ENO => _TMP_MOVE305_ENO);
  _TMP_MOVE308_OUT := MOVE(EN := _TMP_MOVE305_ENO, IN := 0, ENO => _TMP_MOVE308_ENO);
  _TMP_MOVE311_OUT := MOVE(EN := _TMP_MOVE308_ENO, IN := 0, ENO => _TMP_MOVE311_ENO);
  IF _TMP_MOVE311_ENO THEN
    PindahBoxKIRIMem := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE311_ENO THEN
    BCPalletizer := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE311_ENO THEN
    LepasKiriMem := FALSE; (*reset*)
  END_IF;
  SensorRendahKANANMem := NOT(SensorResetKANAN) AND (NOT(SensorTinggiKANAN) AND SensorRendahKANAN OR SensorRendahKANANMem);
  IF _TMP_MOVE305_ENO THEN
      DepanBlkgKIRI := _TMP_MOVE305_OUT;
  END_IF;
  IF _TMP_MOVE308_ENO THEN
      KiriKananKIRI := _TMP_MOVE308_OUT;
  END_IF;
  IF _TMP_MOVE311_ENO THEN
      AtasBawahKIRI := _TMP_MOVE311_OUT;
  END_IF;
  TON6(IN := SensorPickPlaceKanan, PT := T#3s);
  SensorResetKANAN := TON6.Q;
  SensorTinggiKANANMem := NOT(SensorResetKANAN) AND (SensorTinggiKANAN AND SensorRendahKANAN OR SensorTinggiKANANMem);
  TON1(IN := NOT(ExitKanan), PT := T#1000ms);
  IF TON1.Q THEN
    ConveyorKananBelokKiri := TRUE; (*set*)
  END_IF;
  IF TON1.Q THEN
    ConveyorPickPlaceKanan := TRUE; (*set*)
  END_IF;
  _TMP_MOVE121_OUT := MOVE(EN := SensorTinggiKANANMem AND SensorPickPlaceKanan, IN := 270, ENO => _TMP_MOVE121_ENO);
  _TMP_MOVE112_OUT := MOVE(EN := _TMP_MOVE121_ENO, IN := 200, ENO => _TMP_MOVE112_ENO);
  TON2(IN := _TMP_MOVE112_ENO, PT := T#1000ms);
  _TMP_MOVE18_OUT := MOVE(EN := TON2.Q, IN := 795, ENO => _TMP_MOVE18_ENO);
  TON3(IN := _TMP_MOVE18_ENO, PT := T#1000ms);
  IF TON3.Q THEN
    AmbilKANAN := TRUE; (*set*)
  END_IF;
  IF TON3.Q THEN
    PindahBoxKANANMem := TRUE; (*set*)
  END_IF;
  _TMP_MOVE195_OUT := MOVE(EN := SensorRendahKANANMem AND SensorPickPlaceKanan, IN := 270, ENO => _TMP_MOVE195_ENO);
  _TMP_MOVE186_OUT := MOVE(EN := _TMP_MOVE195_ENO, IN := 200, ENO => _TMP_MOVE186_ENO);
  TON10(IN := _TMP_MOVE186_ENO, PT := T#1000ms);
  _TMP_MOVE176_OUT := MOVE(EN := TON10.Q, IN := 10000, ENO => _TMP_MOVE176_ENO);
  TON7(IN := _TMP_MOVE176_ENO, PT := T#1000ms);
  IF TON7.Q THEN
    AmbilKANAN := TRUE; (*set*)
  END_IF;
  IF TON7.Q THEN
    PindahBoxKANANMem := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE112_ENO THEN
      KiriKananKANAN := _TMP_MOVE112_OUT;
  END_IF;
  IF _TMP_MOVE18_ENO THEN
      AtasBawahKANAN := _TMP_MOVE18_OUT;
  END_IF;
  IF _TMP_MOVE186_ENO THEN
      KiriKananKANAN := _TMP_MOVE186_OUT;
  END_IF;
  IF _TMP_MOVE176_ENO THEN
      AtasBawahKANAN := _TMP_MOVE176_OUT;
  END_IF;
  IF _TMP_MOVE121_ENO THEN
      DepanBlkgKANAN := _TMP_MOVE121_OUT;
  END_IF;
  IF _TMP_MOVE195_ENO THEN
      DepanBlkgKANAN := _TMP_MOVE195_OUT;
  END_IF;
  TON4(IN := PindahBoxKANANMem, PT := T#500ms);
  _TMP_MOVE81_OUT := MOVE(EN := TON4.Q, IN := 0, ENO => _TMP_MOVE81_ENO);
  TON12(IN := _TMP_MOVE81_ENO, PT := T#2000ms);
  _TMP_MOVE123_OUT := MOVE(EN := TON12.Q, IN := 800, ENO => _TMP_MOVE123_ENO);
  TON5(IN := _TMP_MOVE123_ENO, PT := T#1000ms);
  _TMP_MOVE138_OUT := MOVE(EN := TON5.Q, IN := 280, ENO => _TMP_MOVE138_ENO);
  IF _TMP_MOVE138_ENO THEN
    AmbilKANAN := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE138_ENO THEN
    PindahBoxKANANMem := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE138_ENO THEN
    BalikTempatKANANMem := TRUE; (*set*)
  END_IF;
  TON8(IN := PindahBoxKANANMem, PT := T#500ms);
  _TMP_MOVE181_OUT := MOVE(EN := TON8.Q, IN := 0, ENO => _TMP_MOVE181_ENO);
  TON9(IN := _TMP_MOVE181_ENO, PT := T#1000ms);
  _TMP_MOVE197_OUT := MOVE(EN := TON9.Q, IN := 800, ENO => _TMP_MOVE197_ENO);
  TON11(IN := _TMP_MOVE197_ENO, PT := T#1000ms);
  _TMP_MOVE212_OUT := MOVE(EN := TON11.Q, IN := 280, ENO => _TMP_MOVE212_ENO);
  IF _TMP_MOVE212_ENO THEN
    AmbilKANAN := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE212_ENO THEN
    PindahBoxKANANMem := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE212_ENO THEN
    BalikTempatKANANMem := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE123_ENO THEN
      KiriKananKANAN := _TMP_MOVE123_OUT;
  END_IF;
  IF _TMP_MOVE197_ENO THEN
      KiriKananKANAN := _TMP_MOVE197_OUT;
  END_IF;
  IF _TMP_MOVE138_ENO THEN
      AtasBawahKANAN := _TMP_MOVE138_OUT;
  END_IF;
  IF _TMP_MOVE212_ENO THEN
      AtasBawahKANAN := _TMP_MOVE212_OUT;
  END_IF;
  IF _TMP_MOVE81_ENO THEN
      AtasBawahKANAN := _TMP_MOVE81_OUT;
  END_IF;
  IF _TMP_MOVE181_ENO THEN
      AtasBawahKANAN := _TMP_MOVE181_OUT;
  END_IF;
  TON15(IN := BalikTempatKANANMem, PT := T#1000ms);
  _TMP_MOVE142_OUT := MOVE(EN := TON15.Q, IN := 0, ENO => _TMP_MOVE142_ENO);
  _TMP_MOVE145_OUT := MOVE(EN := _TMP_MOVE142_ENO, IN := 0, ENO => _TMP_MOVE145_ENO);
  _TMP_MOVE148_OUT := MOVE(EN := _TMP_MOVE145_ENO, IN := 0, ENO => _TMP_MOVE148_ENO);
  IF _TMP_MOVE148_ENO THEN
    BalikTempatKANANMem := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE148_ENO THEN
    ConveyorPickPlaceKanan := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE148_ENO THEN
    ConveyorKanan := TRUE; (*set*)
  END_IF;
  TON16(IN := BalikTempatKANANMem, PT := T#1000ms);
  _TMP_MOVE216_OUT := MOVE(EN := TON16.Q, IN := 0, ENO => _TMP_MOVE216_ENO);
  _TMP_MOVE219_OUT := MOVE(EN := _TMP_MOVE216_ENO, IN := 0, ENO => _TMP_MOVE219_ENO);
  _TMP_MOVE222_OUT := MOVE(EN := _TMP_MOVE219_ENO, IN := 0, ENO => _TMP_MOVE222_ENO);
  IF _TMP_MOVE222_ENO THEN
    BalikTempatKANANMem := FALSE; (*reset*)
  END_IF;
  IF _TMP_MOVE222_ENO THEN
    ConveyorPickPlaceKanan := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE222_ENO THEN
    ConveyorKanan := TRUE; (*set*)
  END_IF;
  IF _TMP_MOVE142_ENO THEN
      AtasBawahKANAN := _TMP_MOVE142_OUT;
  END_IF;
  IF _TMP_MOVE145_ENO THEN
      DepanBlkgKANAN := _TMP_MOVE145_OUT;
  END_IF;
  IF _TMP_MOVE148_ENO THEN
      KiriKananKANAN := _TMP_MOVE148_OUT;
  END_IF;
  IF _TMP_MOVE216_ENO THEN
      AtasBawahKANAN := _TMP_MOVE216_OUT;
  END_IF;
  IF _TMP_MOVE219_ENO THEN
      DepanBlkgKANAN := _TMP_MOVE219_OUT;
  END_IF;
  IF _TMP_MOVE222_ENO THEN
      KiriKananKANAN := _TMP_MOVE222_OUT;
  END_IF;
  IF SensorPickPlaceKanan THEN
    ConveyorKananBelokKiri := FALSE; (*reset*)
  END_IF;
  IF SensorPickPlaceKanan THEN
    ConveyorPickPlaceKanan := FALSE; (*reset*)
  END_IF;
  IF SensorPickPlaceKanan THEN
    ConveyorKanan := FALSE; (*reset*)
  END_IF;
  TON13(IN := SensorPickPlaceKanan, PT := T#2s);
  IF TON13.Q THEN
    ConveyorKananBelokKiri := TRUE; (*set*)
  END_IF;
  IF TON13.Q THEN
    ConveyorPickPlaceKanan := TRUE; (*set*)
  END_IF;
  IF TON13.Q THEN
    ConveyorKanan := TRUE; (*set*)
  END_IF;
  IF SensorPickPlaceKanan THEN
    ConveyorKananBelokKiri := FALSE; (*reset*)
  END_IF;
  IF SensorPickPlaceKanan THEN
    ConveyorPickPlaceKanan := FALSE; (*reset*)
  END_IF;
  IF SensorPickPlaceKanan THEN
    ConveyorKanan := FALSE; (*reset*)
  END_IF;
  TON14(IN := SensorPickPlaceKanan, PT := T#2s);
  IF TON14.Q THEN
    ConveyorKananBelokKiri := TRUE; (*set*)
  END_IF;
  IF TON14.Q THEN
    ConveyorPickPlaceKanan := TRUE; (*set*)
  END_IF;
  IF TON14.Q THEN
    ConveyorKanan := TRUE; (*set*)
  END_IF;
  IF BalikTempatKANANMem THEN
    BCKanan := TRUE; (*set*)
  END_IF;
  IF BalikTempatKANANMem THEN
    BCKananNaik := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : projek_mekatronika_kompleks;
  END_RESOURCE
END_CONFIGURATION
