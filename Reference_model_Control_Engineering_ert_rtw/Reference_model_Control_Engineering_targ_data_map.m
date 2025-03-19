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
        ;% Auto data (Reference_model_Control_Engineering_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_P.Noise_Mean
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_P.Noise_StdDev
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Reference_model_Control_Engineering_P.Noise_Seed
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_P.SFunction_P1_Size_k
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% Reference_model_Control_Engineering_P.SFunction_P1
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_P.SFunction_P2_Size
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 6;

                    ;% Reference_model_Control_Engineering_P.SFunction_P2
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 8;

                    ;% Reference_model_Control_Engineering_P.ec_Ebox_P1_Size
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 9;

                    ;% Reference_model_Control_Engineering_P.ec_Ebox_P1
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% Reference_model_Control_Engineering_P.count2rad_Gain
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% Reference_model_Control_Engineering_P.Quantizer1_Interval
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% Reference_model_Control_Engineering_P.Gain1_Gain
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 14;

                    ;% Reference_model_Control_Engineering_P.Dctpd_P1_Size
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 15;

                    ;% Reference_model_Control_Engineering_P.Dctpd_P1
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 17;

                    ;% Reference_model_Control_Engineering_P.Dctpd_P2_Size
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 18;

                    ;% Reference_model_Control_Engineering_P.Dctpd_P2
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 20;

                    ;% Reference_model_Control_Engineering_P.Dctpd_P3_Size
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 21;

                    ;% Reference_model_Control_Engineering_P.Dctpd_P3
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 23;

                    ;% Reference_model_Control_Engineering_P.Dct2lowpass_P1_Size
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 24;

                    ;% Reference_model_Control_Engineering_P.Dct2lowpass_P1
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 26;

                    ;% Reference_model_Control_Engineering_P.Dct2lowpass_P2_Size
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 27;

                    ;% Reference_model_Control_Engineering_P.Dct2lowpass_P2
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 29;

                    ;% Reference_model_Control_Engineering_P.Dct2lowpass_P3_Size
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 30;

                    ;% Reference_model_Control_Engineering_P.Dct2lowpass_P3
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 32;

                    ;% Reference_model_Control_Engineering_P.Constant_Value
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 33;

                    ;% Reference_model_Control_Engineering_P.Constant1_Value
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 35;

                    ;% Reference_model_Control_Engineering_P.Constant2_Value
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 43;

                    ;% Reference_model_Control_Engineering_P.Gain_Gain
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 44;

                    ;% Reference_model_Control_Engineering_P.Saturation_UpperSat
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 45;

                    ;% Reference_model_Control_Engineering_P.Saturation_LowerSat
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 46;

                    ;% Reference_model_Control_Engineering_P.Saturation_UpperSat_d
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 47;

                    ;% Reference_model_Control_Engineering_P.Saturation_LowerSat_e
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 38;
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
        nTotSects     = 1;
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
        ;% Auto data (Reference_model_Control_Engineering_B)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_B.Noise
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_B.SFunction
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Reference_model_Control_Engineering_B.ec_Ebox_o1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_B.ec_Ebox_o2
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_B.ec_Ebox_o3
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% Reference_model_Control_Engineering_B.Selectencoder
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 14;

                    ;% Reference_model_Control_Engineering_B.Startsetpoint
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 15;

                    ;% Reference_model_Control_Engineering_B.SFunction_c
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 16;

                    ;% Reference_model_Control_Engineering_B.Buffer
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

                    ;% Reference_model_Control_Engineering_B.Gain1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 22;

                    ;% Reference_model_Control_Engineering_B.Dctpd
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 23;

                    ;% Reference_model_Control_Engineering_B.Dct2lowpass
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 24;

                    ;% Reference_model_Control_Engineering_B.Sum1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 25;

                    ;% Reference_model_Control_Engineering_B.TmpSignalConversionAtToWorkspac
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 26;

                    ;% Reference_model_Control_Engineering_B.Constant1
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 28;

                    ;% Reference_model_Control_Engineering_B.Gain
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 36;

                    ;% Reference_model_Control_Engineering_B.Saturation
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 38;

                    ;% Reference_model_Control_Engineering_B.Downsample
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 40;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        sectIdxOffset = 1;

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
        ;% Auto data (Reference_model_Control_Engineering_DW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.NextOutput
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_DW.Downsample_Buffer
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Reference_model_Control_Engineering_DW.fileID
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_DW.SFunction_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_DW.Dctpd_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 55;

                    ;% Reference_model_Control_Engineering_DW.Dct2lowpass_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 57;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.ToWorkspace_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_DW.Live_Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.RandSeed
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_DW.NS
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.NF
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.busy
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_DW.eml_openfiles
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


    targMap.checksum0 = 3477193817;
    targMap.checksum1 = 1569805435;
    targMap.checksum2 = 2429156659;
    targMap.checksum3 = 1168022689;

