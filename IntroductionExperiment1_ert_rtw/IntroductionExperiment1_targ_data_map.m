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
        ;% Auto data (IntroductionExperiment1_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% IntroductionExperiment1_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% IntroductionExperiment1_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment1_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% IntroductionExperiment1_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 31;
            section.data(31)  = dumData; %prealloc

                    ;% IntroductionExperiment1_P.Noise_Mean
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_P.Noise_StdDev
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% IntroductionExperiment1_P.Noise_Seed
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% IntroductionExperiment1_P.SFunction_P1_Size_k
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% IntroductionExperiment1_P.SFunction_P1
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 5;

                    ;% IntroductionExperiment1_P.SFunction_P2_Size
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 6;

                    ;% IntroductionExperiment1_P.SFunction_P2
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 8;

                    ;% IntroductionExperiment1_P.ec_Ebox_P1_Size
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 9;

                    ;% IntroductionExperiment1_P.ec_Ebox_P1
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% IntroductionExperiment1_P.count2rad_Gain
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% IntroductionExperiment1_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% IntroductionExperiment1_P.Dctleadlag_P1_Size
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 14;

                    ;% IntroductionExperiment1_P.Dctleadlag_P1
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 16;

                    ;% IntroductionExperiment1_P.Dctleadlag_P2_Size
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 17;

                    ;% IntroductionExperiment1_P.Dctleadlag_P2
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 19;

                    ;% IntroductionExperiment1_P.Dctleadlag_P3_Size
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 20;

                    ;% IntroductionExperiment1_P.Dctleadlag_P3
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 22;

                    ;% IntroductionExperiment1_P.Dct2lowpass_P1_Size
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 23;

                    ;% IntroductionExperiment1_P.Dct2lowpass_P1
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 25;

                    ;% IntroductionExperiment1_P.Dct2lowpass_P2_Size
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 26;

                    ;% IntroductionExperiment1_P.Dct2lowpass_P2
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 28;

                    ;% IntroductionExperiment1_P.Dct2lowpass_P3_Size
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 29;

                    ;% IntroductionExperiment1_P.Dct2lowpass_P3
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 31;

                    ;% IntroductionExperiment1_P.Constant_Value
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 32;

                    ;% IntroductionExperiment1_P.Constant1_Value
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 34;

                    ;% IntroductionExperiment1_P.Constant2_Value
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 42;

                    ;% IntroductionExperiment1_P.Gain_Gain
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 43;

                    ;% IntroductionExperiment1_P.Saturation_UpperSat
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 44;

                    ;% IntroductionExperiment1_P.Saturation_LowerSat
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 45;

                    ;% IntroductionExperiment1_P.Saturation_UpperSat_d
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 46;

                    ;% IntroductionExperiment1_P.Saturation_LowerSat_e
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 47;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment1_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 37;
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
        ;% Auto data (IntroductionExperiment1_B)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% IntroductionExperiment1_B.Sum4
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_B.SFunction
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% IntroductionExperiment1_B.ec_Ebox_o1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% IntroductionExperiment1_B.ec_Ebox_o2
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% IntroductionExperiment1_B.ec_Ebox_o3
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% IntroductionExperiment1_B.Selectencoder
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 14;

                    ;% IntroductionExperiment1_B.TmpSignalConversionAtToWorkspac
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 15;

                    ;% IntroductionExperiment1_B.Gain1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 17;

                    ;% IntroductionExperiment1_B.Dctleadlag
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 18;

                    ;% IntroductionExperiment1_B.Dct2lowpass
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 19;

                    ;% IntroductionExperiment1_B.Constant1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 20;

                    ;% IntroductionExperiment1_B.Gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 28;

                    ;% IntroductionExperiment1_B.Saturation
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 30;

                    ;% IntroductionExperiment1_B.SFunction_c
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 32;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% IntroductionExperiment1_B.Startsetpoint
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_B.Downsample
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

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
        ;% Auto data (IntroductionExperiment1_DW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.NextOutput
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_DW.Downsample_Buffer
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% IntroductionExperiment1_DW.fileID
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% IntroductionExperiment1_DW.Dctleadlag_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% IntroductionExperiment1_DW.Dct2lowpass_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% IntroductionExperiment1_DW.SFunction_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.ToWorkspace_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_DW.Live_Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.RandSeed
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% IntroductionExperiment1_DW.NS
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.NF
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.busy
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% IntroductionExperiment1_DW.eml_openfiles
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


    targMap.checksum0 = 134840207;
    targMap.checksum1 = 3856972602;
    targMap.checksum2 = 2177003220;
    targMap.checksum3 = 4232049150;

