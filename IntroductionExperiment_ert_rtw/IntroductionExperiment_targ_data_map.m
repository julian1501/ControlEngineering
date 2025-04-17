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
        ;% Auto data (IntroductionExperiment_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% IntroductionExperiment_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% IntroductionExperiment_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% IntroductionExperiment_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 44;
            section.data(44)  = dumData; %prealloc

                    ;% IntroductionExperiment_P.SFunction_P1_Size_k
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_P.SFunction_P1
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 2;

                    ;% IntroductionExperiment_P.SFunction_P2_Size
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 3;

                    ;% IntroductionExperiment_P.SFunction_P2
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 5;

                    ;% IntroductionExperiment_P.ec_Ebox_P1_Size
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% IntroductionExperiment_P.ec_Ebox_P1
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 8;

                    ;% IntroductionExperiment_P.count2rad_Gain
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 9;

                    ;% IntroductionExperiment_P.Gain_Gain
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 10;

                    ;% IntroductionExperiment_P.Quantizer1_Interval
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% IntroductionExperiment_P.Gain2_Gain
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% IntroductionExperiment_P.Dctleadlag2_P1_Size
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% IntroductionExperiment_P.Dctleadlag2_P1
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 15;

                    ;% IntroductionExperiment_P.Dctleadlag2_P2_Size
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 16;

                    ;% IntroductionExperiment_P.Dctleadlag2_P2
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 18;

                    ;% IntroductionExperiment_P.Dctleadlag2_P3_Size
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 19;

                    ;% IntroductionExperiment_P.Dctleadlag2_P3
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 21;

                    ;% IntroductionExperiment_P.Dct1lowpass3_P1_Size
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 22;

                    ;% IntroductionExperiment_P.Dct1lowpass3_P1
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 24;

                    ;% IntroductionExperiment_P.Dct1lowpass3_P2_Size
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 25;

                    ;% IntroductionExperiment_P.Dct1lowpass3_P2
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 27;

                    ;% IntroductionExperiment_P.Dctnotch4_P1_Size
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 28;

                    ;% IntroductionExperiment_P.Dctnotch4_P1
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 30;

                    ;% IntroductionExperiment_P.Dctnotch4_P2_Size
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 31;

                    ;% IntroductionExperiment_P.Dctnotch4_P2
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 33;

                    ;% IntroductionExperiment_P.Dctnotch4_P3_Size
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 34;

                    ;% IntroductionExperiment_P.Dctnotch4_P3
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 36;

                    ;% IntroductionExperiment_P.Dctnotch4_P4_Size
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 37;

                    ;% IntroductionExperiment_P.Dctnotch4_P4
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 39;

                    ;% IntroductionExperiment_P.Dctnotch4_P5_Size
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 40;

                    ;% IntroductionExperiment_P.Dctnotch4_P5
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 42;

                    ;% IntroductionExperiment_P.Kfa_Gain
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 43;

                    ;% IntroductionExperiment_P.Kfc_Gain
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 44;

                    ;% IntroductionExperiment_P.Kfv_Gain
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 45;

                    ;% IntroductionExperiment_P.Constant_Value
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 46;

                    ;% IntroductionExperiment_P.Constant1_Value
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 48;

                    ;% IntroductionExperiment_P.Constant2_Value
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 56;

                    ;% IntroductionExperiment_P.Gain_Gain_g
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 57;

                    ;% IntroductionExperiment_P.Noise_Mean
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 58;

                    ;% IntroductionExperiment_P.Noise_StdDev
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 59;

                    ;% IntroductionExperiment_P.Noise_Seed
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 60;

                    ;% IntroductionExperiment_P.Saturation_UpperSat
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 61;

                    ;% IntroductionExperiment_P.Saturation_LowerSat
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 62;

                    ;% IntroductionExperiment_P.Saturation_UpperSat_d
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 63;

                    ;% IntroductionExperiment_P.Saturation_LowerSat_e
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 64;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 50;
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
        ;% Auto data (IntroductionExperiment_B)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% IntroductionExperiment_B.SFunction
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_B.ec_Ebox_o1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% IntroductionExperiment_B.ec_Ebox_o2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% IntroductionExperiment_B.ec_Ebox_o3
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% IntroductionExperiment_B.Startsetpoint
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 13;

                    ;% IntroductionExperiment_B.SFunction_c
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 14;

                    ;% IntroductionExperiment_B.Buffer
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 17;

                    ;% IntroductionExperiment_B.Gain2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 20;

                    ;% IntroductionExperiment_B.Dctleadlag2
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 21;

                    ;% IntroductionExperiment_B.Dct1lowpass3
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 22;

                    ;% IntroductionExperiment_B.Dctnotch4
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 23;

                    ;% IntroductionExperiment_B.Constant1
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 24;

                    ;% IntroductionExperiment_B.Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 32;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% IntroductionExperiment_B.Sum1
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_B.Saturation
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% IntroductionExperiment_B.Downsample
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 3;

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
        ;% Auto data (IntroductionExperiment_DW)
        ;%
            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_DW.NextOutput
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% IntroductionExperiment_DW.fileID
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% IntroductionExperiment_DW.SFunction_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% IntroductionExperiment_DW.Dctleadlag2_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 55;

                    ;% IntroductionExperiment_DW.Dct1lowpass3_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 57;

                    ;% IntroductionExperiment_DW.Dctnotch4_RWORK
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 59;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.Live_Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.RandSeed
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment_DW.NS
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.NF
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.busy
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment_DW.eml_openfiles
                    section.data(1).logicalSrcIdx = 13;
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


    targMap.checksum0 = 257292962;
    targMap.checksum1 = 1079310480;
    targMap.checksum2 = 1037825315;
    targMap.checksum3 = 3349255053;

