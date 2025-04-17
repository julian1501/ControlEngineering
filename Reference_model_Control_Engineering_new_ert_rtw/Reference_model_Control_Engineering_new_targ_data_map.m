    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Reference_model_Control_Engineering_new_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_new_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 63;
            section.data(63)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_P.SFunction_P1_Size_k
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_P.SFunction_P1
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_new_P.SFunction_P2_Size
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 3;

                    ;% Reference_model_Control_Engineering_new_P.SFunction_P2
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_new_P.ec_Ebox_P1_Size
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% Reference_model_Control_Engineering_new_P.ec_Ebox_P1
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 8;

                    ;% Reference_model_Control_Engineering_new_P.count2rad_Gain
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 9;

                    ;% Reference_model_Control_Engineering_new_P.Gain_Gain
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 10;

                    ;% Reference_model_Control_Engineering_new_P.Quantizer1_Interval
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% Reference_model_Control_Engineering_new_P.Gain1_Gain
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% Reference_model_Control_Engineering_new_P.Ka_Gain
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% Reference_model_Control_Engineering_new_P.Kfc_Gain
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 14;

                    ;% Reference_model_Control_Engineering_new_P.Kv_Gain
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 15;

                    ;% Reference_model_Control_Engineering_new_P.Constant_Value
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 16;

                    ;% Reference_model_Control_Engineering_new_P.Constant1_Value
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 18;

                    ;% Reference_model_Control_Engineering_new_P.Constant2_Value
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 26;

                    ;% Reference_model_Control_Engineering_new_P.Gain_Gain_g
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 27;

                    ;% Reference_model_Control_Engineering_new_P.Gain5_Gain
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 28;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P1_Size
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 29;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P1
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 31;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P2_Size
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 32;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P2
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 34;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P3_Size
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 35;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P3
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 37;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P4_Size
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 38;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P4
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 40;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P5_Size
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 41;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch8_P5
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 43;

                    ;% Reference_model_Control_Engineering_new_P.Dctleadlag4_P1_Size
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 44;

                    ;% Reference_model_Control_Engineering_new_P.Dctleadlag4_P1
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 46;

                    ;% Reference_model_Control_Engineering_new_P.Dctleadlag4_P2_Size
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 47;

                    ;% Reference_model_Control_Engineering_new_P.Dctleadlag4_P2
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 49;

                    ;% Reference_model_Control_Engineering_new_P.Dctleadlag4_P3_Size
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 50;

                    ;% Reference_model_Control_Engineering_new_P.Dctleadlag4_P3
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 52;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P1_Size
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 53;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P1
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 55;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P2_Size
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 56;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P2
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 58;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P3_Size
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 59;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P3
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 61;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P4_Size
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 62;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P4
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 64;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P5_Size
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 65;

                    ;% Reference_model_Control_Engineering_new_P.Dctnotch9_P5
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 67;

                    ;% Reference_model_Control_Engineering_new_P.Dctdoubleintegrator4_P1_Size
                    section.data(45).logicalSrcIdx = 50;
                    section.data(45).dtTransOffset = 68;

                    ;% Reference_model_Control_Engineering_new_P.Dctdoubleintegrator4_P1
                    section.data(46).logicalSrcIdx = 51;
                    section.data(46).dtTransOffset = 70;

                    ;% Reference_model_Control_Engineering_new_P.Dctdoubleintegrator4_P2_Size
                    section.data(47).logicalSrcIdx = 52;
                    section.data(47).dtTransOffset = 71;

                    ;% Reference_model_Control_Engineering_new_P.Dctdoubleintegrator4_P2
                    section.data(48).logicalSrcIdx = 53;
                    section.data(48).dtTransOffset = 73;

                    ;% Reference_model_Control_Engineering_new_P.Dctdoubleintegrator4_P3_Size
                    section.data(49).logicalSrcIdx = 54;
                    section.data(49).dtTransOffset = 74;

                    ;% Reference_model_Control_Engineering_new_P.Dctdoubleintegrator4_P3
                    section.data(50).logicalSrcIdx = 55;
                    section.data(50).dtTransOffset = 76;

                    ;% Reference_model_Control_Engineering_new_P.Dct2lowpass4_P1_Size
                    section.data(51).logicalSrcIdx = 56;
                    section.data(51).dtTransOffset = 77;

                    ;% Reference_model_Control_Engineering_new_P.Dct2lowpass4_P1
                    section.data(52).logicalSrcIdx = 57;
                    section.data(52).dtTransOffset = 79;

                    ;% Reference_model_Control_Engineering_new_P.Dct2lowpass4_P2_Size
                    section.data(53).logicalSrcIdx = 58;
                    section.data(53).dtTransOffset = 80;

                    ;% Reference_model_Control_Engineering_new_P.Dct2lowpass4_P2
                    section.data(54).logicalSrcIdx = 59;
                    section.data(54).dtTransOffset = 82;

                    ;% Reference_model_Control_Engineering_new_P.Dct2lowpass4_P3_Size
                    section.data(55).logicalSrcIdx = 60;
                    section.data(55).dtTransOffset = 83;

                    ;% Reference_model_Control_Engineering_new_P.Dct2lowpass4_P3
                    section.data(56).logicalSrcIdx = 61;
                    section.data(56).dtTransOffset = 85;

                    ;% Reference_model_Control_Engineering_new_P.Noise_Mean
                    section.data(57).logicalSrcIdx = 62;
                    section.data(57).dtTransOffset = 86;

                    ;% Reference_model_Control_Engineering_new_P.Noise_StdDev
                    section.data(58).logicalSrcIdx = 63;
                    section.data(58).dtTransOffset = 87;

                    ;% Reference_model_Control_Engineering_new_P.Noise_Seed
                    section.data(59).logicalSrcIdx = 64;
                    section.data(59).dtTransOffset = 88;

                    ;% Reference_model_Control_Engineering_new_P.Saturation_UpperSat
                    section.data(60).logicalSrcIdx = 65;
                    section.data(60).dtTransOffset = 89;

                    ;% Reference_model_Control_Engineering_new_P.Saturation_LowerSat
                    section.data(61).logicalSrcIdx = 66;
                    section.data(61).dtTransOffset = 90;

                    ;% Reference_model_Control_Engineering_new_P.Saturation_UpperSat_d
                    section.data(62).logicalSrcIdx = 67;
                    section.data(62).dtTransOffset = 91;

                    ;% Reference_model_Control_Engineering_new_P.Saturation_LowerSat_e
                    section.data(63).logicalSrcIdx = 68;
                    section.data(63).dtTransOffset = 92;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Reference_model_Control_Engineering_new_B)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_B.ec_Ebox_o1
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_B.ec_Ebox_o2
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_new_B.ec_Ebox_o3
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_new_B.Constant1
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 12;

                    ;% Reference_model_Control_Engineering_new_B.Gain
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_B.SFunction
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_B.Startsetpoint
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% Reference_model_Control_Engineering_new_B.SFunction_c
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_new_B.Sum2
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_new_B.Sum
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 6;

                    ;% Reference_model_Control_Engineering_new_B.Buffer
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 7;

                    ;% Reference_model_Control_Engineering_new_B.TmpSignalConversionAtToWorkspac
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 10;

                    ;% Reference_model_Control_Engineering_new_B.Gain5
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 12;

                    ;% Reference_model_Control_Engineering_new_B.Dctnotch8
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 13;

                    ;% Reference_model_Control_Engineering_new_B.Dctleadlag4
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 14;

                    ;% Reference_model_Control_Engineering_new_B.Dctnotch9
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 15;

                    ;% Reference_model_Control_Engineering_new_B.Dctdoubleintegrator4
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 16;

                    ;% Reference_model_Control_Engineering_new_B.Dct2lowpass4
                    section.data(13).logicalSrcIdx = 17;
                    section.data(13).dtTransOffset = 17;

                    ;% Reference_model_Control_Engineering_new_B.Noise
                    section.data(14).logicalSrcIdx = 18;
                    section.data(14).dtTransOffset = 18;

                    ;% Reference_model_Control_Engineering_new_B.Saturation
                    section.data(15).logicalSrcIdx = 19;
                    section.data(15).dtTransOffset = 19;

                    ;% Reference_model_Control_Engineering_new_B.Downsample
                    section.data(16).logicalSrcIdx = 20;
                    section.data(16).dtTransOffset = 21;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Reference_model_Control_Engineering_new_DW)
        ;%
            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_DW.NextOutput
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Reference_model_Control_Engineering_new_DW.fileID
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_new_DW.SFunction_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_new_DW.Dctnotch8_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 55;

                    ;% Reference_model_Control_Engineering_new_DW.Dctleadlag4_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 59;

                    ;% Reference_model_Control_Engineering_new_DW.Dctnotch9_RWORK
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 61;

                    ;% Reference_model_Control_Engineering_new_DW.Dctdoubleintegrator4_RWORK
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 65;

                    ;% Reference_model_Control_Engineering_new_DW.Dct2lowpass4_RWORK
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 69;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.ToWorkspace_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_DW.Live_Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.RandSeed
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_new_DW.NS
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.NF
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.busy
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_new_DW.eml_openfiles
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2296827966;
    targMap.checksum1 = 1794093440;
    targMap.checksum2 = 3183298516;
    targMap.checksum3 = 1011816324;

