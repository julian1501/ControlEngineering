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
        ;% Auto data (Reference_model_Control_Engineering_4_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_4_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 257;
            section.data(257)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_P.count2rad_Gain
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_P.Quantizer1_Interval
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Reference_model_Control_Engineering_4_P.SFunction_P1_Size_k
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% Reference_model_Control_Engineering_4_P.SFunction_P1
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_4_P.SFunction_P2_Size
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_4_P.SFunction_P2
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 7;

                    ;% Reference_model_Control_Engineering_4_P.ec_Ebox_P1_Size
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 8;

                    ;% Reference_model_Control_Engineering_4_P.ec_Ebox_P1
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 10;

                    ;% Reference_model_Control_Engineering_4_P.Gain1_Gain
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% Reference_model_Control_Engineering_4_P.Ka_Gain
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% Reference_model_Control_Engineering_4_P.Kfc_Gain
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% Reference_model_Control_Engineering_4_P.Kv_Gain
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 14;

                    ;% Reference_model_Control_Engineering_4_P.Constant_Value
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 15;

                    ;% Reference_model_Control_Engineering_4_P.Constant1_Value
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 17;

                    ;% Reference_model_Control_Engineering_4_P.Constant2_Value
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 25;

                    ;% Reference_model_Control_Engineering_4_P.Gain_Gain
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 26;

                    ;% Reference_model_Control_Engineering_4_P.Gain5_Gain
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 27;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P1_Size
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 28;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P1
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 30;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P2_Size
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 31;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P2
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 33;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P3_Size
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 34;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P3
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 36;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P4_Size
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 37;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P4
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 39;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P5_Size
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 40;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch8_P5
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 42;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag4_P1_Size
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 43;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag4_P1
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 45;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag4_P2_Size
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 46;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag4_P2
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 48;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag4_P3_Size
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 49;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag4_P3
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 51;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P1_Size
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 52;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P1
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 54;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P2_Size
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 55;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P2
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 57;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P3_Size
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 58;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P3
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 60;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P4_Size
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 61;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P4
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 63;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P5_Size
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 64;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch9_P5
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 66;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P1_Size
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 67;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P1
                    section.data(45).logicalSrcIdx = 50;
                    section.data(45).dtTransOffset = 69;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P2_Size
                    section.data(46).logicalSrcIdx = 51;
                    section.data(46).dtTransOffset = 70;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P2
                    section.data(47).logicalSrcIdx = 52;
                    section.data(47).dtTransOffset = 72;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P3_Size
                    section.data(48).logicalSrcIdx = 53;
                    section.data(48).dtTransOffset = 73;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P3
                    section.data(49).logicalSrcIdx = 54;
                    section.data(49).dtTransOffset = 75;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass4_P1_Size
                    section.data(50).logicalSrcIdx = 55;
                    section.data(50).dtTransOffset = 76;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass4_P1
                    section.data(51).logicalSrcIdx = 56;
                    section.data(51).dtTransOffset = 78;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass4_P2_Size
                    section.data(52).logicalSrcIdx = 57;
                    section.data(52).dtTransOffset = 79;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass4_P2
                    section.data(53).logicalSrcIdx = 58;
                    section.data(53).dtTransOffset = 81;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass4_P3_Size
                    section.data(54).logicalSrcIdx = 59;
                    section.data(54).dtTransOffset = 82;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass4_P3
                    section.data(55).logicalSrcIdx = 60;
                    section.data(55).dtTransOffset = 84;

                    ;% Reference_model_Control_Engineering_4_P.Noise_Mean
                    section.data(56).logicalSrcIdx = 61;
                    section.data(56).dtTransOffset = 85;

                    ;% Reference_model_Control_Engineering_4_P.Noise_StdDev
                    section.data(57).logicalSrcIdx = 62;
                    section.data(57).dtTransOffset = 86;

                    ;% Reference_model_Control_Engineering_4_P.Noise_Seed
                    section.data(58).logicalSrcIdx = 63;
                    section.data(58).dtTransOffset = 87;

                    ;% Reference_model_Control_Engineering_4_P.Saturation_UpperSat
                    section.data(59).logicalSrcIdx = 64;
                    section.data(59).dtTransOffset = 88;

                    ;% Reference_model_Control_Engineering_4_P.Saturation_LowerSat
                    section.data(60).logicalSrcIdx = 65;
                    section.data(60).dtTransOffset = 89;

                    ;% Reference_model_Control_Engineering_4_P.Saturation_UpperSat_d
                    section.data(61).logicalSrcIdx = 66;
                    section.data(61).dtTransOffset = 90;

                    ;% Reference_model_Control_Engineering_4_P.Saturation_LowerSat_e
                    section.data(62).logicalSrcIdx = 67;
                    section.data(62).dtTransOffset = 91;

                    ;% Reference_model_Control_Engineering_4_P.Gain2_Gain
                    section.data(63).logicalSrcIdx = 68;
                    section.data(63).dtTransOffset = 92;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size
                    section.data(64).logicalSrcIdx = 69;
                    section.data(64).dtTransOffset = 93;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1
                    section.data(65).logicalSrcIdx = 70;
                    section.data(65).dtTransOffset = 95;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size
                    section.data(66).logicalSrcIdx = 71;
                    section.data(66).dtTransOffset = 96;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2
                    section.data(67).logicalSrcIdx = 72;
                    section.data(67).dtTransOffset = 98;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size
                    section.data(68).logicalSrcIdx = 73;
                    section.data(68).dtTransOffset = 99;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3
                    section.data(69).logicalSrcIdx = 74;
                    section.data(69).dtTransOffset = 101;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size
                    section.data(70).logicalSrcIdx = 75;
                    section.data(70).dtTransOffset = 102;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4
                    section.data(71).logicalSrcIdx = 76;
                    section.data(71).dtTransOffset = 104;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size
                    section.data(72).logicalSrcIdx = 77;
                    section.data(72).dtTransOffset = 105;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5
                    section.data(73).logicalSrcIdx = 78;
                    section.data(73).dtTransOffset = 107;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size
                    section.data(74).logicalSrcIdx = 79;
                    section.data(74).dtTransOffset = 108;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1
                    section.data(75).logicalSrcIdx = 80;
                    section.data(75).dtTransOffset = 110;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size
                    section.data(76).logicalSrcIdx = 81;
                    section.data(76).dtTransOffset = 111;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2
                    section.data(77).logicalSrcIdx = 82;
                    section.data(77).dtTransOffset = 113;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size
                    section.data(78).logicalSrcIdx = 83;
                    section.data(78).dtTransOffset = 114;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3
                    section.data(79).logicalSrcIdx = 84;
                    section.data(79).dtTransOffset = 116;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size
                    section.data(80).logicalSrcIdx = 85;
                    section.data(80).dtTransOffset = 117;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1
                    section.data(81).logicalSrcIdx = 86;
                    section.data(81).dtTransOffset = 119;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size
                    section.data(82).logicalSrcIdx = 87;
                    section.data(82).dtTransOffset = 120;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2
                    section.data(83).logicalSrcIdx = 88;
                    section.data(83).dtTransOffset = 122;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size
                    section.data(84).logicalSrcIdx = 89;
                    section.data(84).dtTransOffset = 123;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3
                    section.data(85).logicalSrcIdx = 90;
                    section.data(85).dtTransOffset = 125;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size
                    section.data(86).logicalSrcIdx = 91;
                    section.data(86).dtTransOffset = 126;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4
                    section.data(87).logicalSrcIdx = 92;
                    section.data(87).dtTransOffset = 128;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size
                    section.data(88).logicalSrcIdx = 93;
                    section.data(88).dtTransOffset = 129;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5
                    section.data(89).logicalSrcIdx = 94;
                    section.data(89).dtTransOffset = 131;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size
                    section.data(90).logicalSrcIdx = 95;
                    section.data(90).dtTransOffset = 132;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1
                    section.data(91).logicalSrcIdx = 96;
                    section.data(91).dtTransOffset = 134;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size
                    section.data(92).logicalSrcIdx = 97;
                    section.data(92).dtTransOffset = 135;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2
                    section.data(93).logicalSrcIdx = 98;
                    section.data(93).dtTransOffset = 137;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size
                    section.data(94).logicalSrcIdx = 99;
                    section.data(94).dtTransOffset = 138;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3
                    section.data(95).logicalSrcIdx = 100;
                    section.data(95).dtTransOffset = 140;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size
                    section.data(96).logicalSrcIdx = 101;
                    section.data(96).dtTransOffset = 141;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1
                    section.data(97).logicalSrcIdx = 102;
                    section.data(97).dtTransOffset = 143;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size
                    section.data(98).logicalSrcIdx = 103;
                    section.data(98).dtTransOffset = 144;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2
                    section.data(99).logicalSrcIdx = 104;
                    section.data(99).dtTransOffset = 146;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size
                    section.data(100).logicalSrcIdx = 105;
                    section.data(100).dtTransOffset = 147;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3
                    section.data(101).logicalSrcIdx = 106;
                    section.data(101).dtTransOffset = 149;

                    ;% Reference_model_Control_Engineering_4_P.Gain2_Gain_f
                    section.data(102).logicalSrcIdx = 107;
                    section.data(102).dtTransOffset = 150;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_f
                    section.data(103).logicalSrcIdx = 108;
                    section.data(103).dtTransOffset = 151;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_l
                    section.data(104).logicalSrcIdx = 109;
                    section.data(104).dtTransOffset = 153;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_k
                    section.data(105).logicalSrcIdx = 110;
                    section.data(105).dtTransOffset = 154;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_m
                    section.data(106).logicalSrcIdx = 111;
                    section.data(106).dtTransOffset = 156;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_e
                    section.data(107).logicalSrcIdx = 112;
                    section.data(107).dtTransOffset = 157;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_g
                    section.data(108).logicalSrcIdx = 113;
                    section.data(108).dtTransOffset = 159;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_o
                    section.data(109).logicalSrcIdx = 114;
                    section.data(109).dtTransOffset = 160;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_j
                    section.data(110).logicalSrcIdx = 115;
                    section.data(110).dtTransOffset = 162;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_e
                    section.data(111).logicalSrcIdx = 116;
                    section.data(111).dtTransOffset = 163;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_j
                    section.data(112).logicalSrcIdx = 117;
                    section.data(112).dtTransOffset = 165;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_d
                    section.data(113).logicalSrcIdx = 118;
                    section.data(113).dtTransOffset = 166;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_k
                    section.data(114).logicalSrcIdx = 119;
                    section.data(114).dtTransOffset = 168;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_c
                    section.data(115).logicalSrcIdx = 120;
                    section.data(115).dtTransOffset = 169;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_p
                    section.data(116).logicalSrcIdx = 121;
                    section.data(116).dtTransOffset = 171;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_m
                    section.data(117).logicalSrcIdx = 122;
                    section.data(117).dtTransOffset = 172;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_f
                    section.data(118).logicalSrcIdx = 123;
                    section.data(118).dtTransOffset = 174;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_f
                    section.data(119).logicalSrcIdx = 124;
                    section.data(119).dtTransOffset = 175;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_g
                    section.data(120).logicalSrcIdx = 125;
                    section.data(120).dtTransOffset = 177;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_e
                    section.data(121).logicalSrcIdx = 126;
                    section.data(121).dtTransOffset = 178;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_i
                    section.data(122).logicalSrcIdx = 127;
                    section.data(122).dtTransOffset = 180;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_f
                    section.data(123).logicalSrcIdx = 128;
                    section.data(123).dtTransOffset = 181;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_n
                    section.data(124).logicalSrcIdx = 129;
                    section.data(124).dtTransOffset = 183;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_p
                    section.data(125).logicalSrcIdx = 130;
                    section.data(125).dtTransOffset = 184;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_j
                    section.data(126).logicalSrcIdx = 131;
                    section.data(126).dtTransOffset = 186;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_p
                    section.data(127).logicalSrcIdx = 132;
                    section.data(127).dtTransOffset = 187;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_o
                    section.data(128).logicalSrcIdx = 133;
                    section.data(128).dtTransOffset = 189;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_l
                    section.data(129).logicalSrcIdx = 134;
                    section.data(129).dtTransOffset = 190;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_m
                    section.data(130).logicalSrcIdx = 135;
                    section.data(130).dtTransOffset = 192;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_i
                    section.data(131).logicalSrcIdx = 136;
                    section.data(131).dtTransOffset = 193;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_d
                    section.data(132).logicalSrcIdx = 137;
                    section.data(132).dtTransOffset = 195;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_i
                    section.data(133).logicalSrcIdx = 138;
                    section.data(133).dtTransOffset = 196;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_j
                    section.data(134).logicalSrcIdx = 139;
                    section.data(134).dtTransOffset = 198;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_g
                    section.data(135).logicalSrcIdx = 140;
                    section.data(135).dtTransOffset = 199;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_p
                    section.data(136).logicalSrcIdx = 141;
                    section.data(136).dtTransOffset = 201;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_a
                    section.data(137).logicalSrcIdx = 142;
                    section.data(137).dtTransOffset = 202;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_b
                    section.data(138).logicalSrcIdx = 143;
                    section.data(138).dtTransOffset = 204;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_a
                    section.data(139).logicalSrcIdx = 144;
                    section.data(139).dtTransOffset = 205;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_d
                    section.data(140).logicalSrcIdx = 145;
                    section.data(140).dtTransOffset = 207;

                    ;% Reference_model_Control_Engineering_4_P.Gain2_Gain_a
                    section.data(141).logicalSrcIdx = 146;
                    section.data(141).dtTransOffset = 208;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_j
                    section.data(142).logicalSrcIdx = 147;
                    section.data(142).dtTransOffset = 209;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_b
                    section.data(143).logicalSrcIdx = 148;
                    section.data(143).dtTransOffset = 211;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_km
                    section.data(144).logicalSrcIdx = 149;
                    section.data(144).dtTransOffset = 212;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_h
                    section.data(145).logicalSrcIdx = 150;
                    section.data(145).dtTransOffset = 214;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_h
                    section.data(146).logicalSrcIdx = 151;
                    section.data(146).dtTransOffset = 215;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_f
                    section.data(147).logicalSrcIdx = 152;
                    section.data(147).dtTransOffset = 217;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_j
                    section.data(148).logicalSrcIdx = 153;
                    section.data(148).dtTransOffset = 218;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_c
                    section.data(149).logicalSrcIdx = 154;
                    section.data(149).dtTransOffset = 220;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_c
                    section.data(150).logicalSrcIdx = 155;
                    section.data(150).dtTransOffset = 221;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_k
                    section.data(151).logicalSrcIdx = 156;
                    section.data(151).dtTransOffset = 223;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_f
                    section.data(152).logicalSrcIdx = 157;
                    section.data(152).dtTransOffset = 224;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_d
                    section.data(153).logicalSrcIdx = 158;
                    section.data(153).dtTransOffset = 226;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_h
                    section.data(154).logicalSrcIdx = 159;
                    section.data(154).dtTransOffset = 227;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_a
                    section.data(155).logicalSrcIdx = 160;
                    section.data(155).dtTransOffset = 229;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_g
                    section.data(156).logicalSrcIdx = 161;
                    section.data(156).dtTransOffset = 230;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_o
                    section.data(157).logicalSrcIdx = 162;
                    section.data(157).dtTransOffset = 232;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_o
                    section.data(158).logicalSrcIdx = 163;
                    section.data(158).dtTransOffset = 233;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_h
                    section.data(159).logicalSrcIdx = 164;
                    section.data(159).dtTransOffset = 235;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_m
                    section.data(160).logicalSrcIdx = 165;
                    section.data(160).dtTransOffset = 236;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_f
                    section.data(161).logicalSrcIdx = 166;
                    section.data(161).dtTransOffset = 238;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_l
                    section.data(162).logicalSrcIdx = 167;
                    section.data(162).dtTransOffset = 239;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_a
                    section.data(163).logicalSrcIdx = 168;
                    section.data(163).dtTransOffset = 241;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_o
                    section.data(164).logicalSrcIdx = 169;
                    section.data(164).dtTransOffset = 242;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_l
                    section.data(165).logicalSrcIdx = 170;
                    section.data(165).dtTransOffset = 244;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_o
                    section.data(166).logicalSrcIdx = 171;
                    section.data(166).dtTransOffset = 245;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_l
                    section.data(167).logicalSrcIdx = 172;
                    section.data(167).dtTransOffset = 247;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_j
                    section.data(168).logicalSrcIdx = 173;
                    section.data(168).dtTransOffset = 248;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_j
                    section.data(169).logicalSrcIdx = 174;
                    section.data(169).dtTransOffset = 250;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_h
                    section.data(170).logicalSrcIdx = 175;
                    section.data(170).dtTransOffset = 251;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_k
                    section.data(171).logicalSrcIdx = 176;
                    section.data(171).dtTransOffset = 253;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_p
                    section.data(172).logicalSrcIdx = 177;
                    section.data(172).dtTransOffset = 254;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_l
                    section.data(173).logicalSrcIdx = 178;
                    section.data(173).dtTransOffset = 256;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_m
                    section.data(174).logicalSrcIdx = 179;
                    section.data(174).dtTransOffset = 257;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_k
                    section.data(175).logicalSrcIdx = 180;
                    section.data(175).dtTransOffset = 259;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_e
                    section.data(176).logicalSrcIdx = 181;
                    section.data(176).dtTransOffset = 260;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_k
                    section.data(177).logicalSrcIdx = 182;
                    section.data(177).dtTransOffset = 262;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_j
                    section.data(178).logicalSrcIdx = 183;
                    section.data(178).dtTransOffset = 263;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_a
                    section.data(179).logicalSrcIdx = 184;
                    section.data(179).dtTransOffset = 265;

                    ;% Reference_model_Control_Engineering_4_P.Gain2_Gain_d
                    section.data(180).logicalSrcIdx = 185;
                    section.data(180).dtTransOffset = 266;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_c
                    section.data(181).logicalSrcIdx = 186;
                    section.data(181).dtTransOffset = 267;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_a
                    section.data(182).logicalSrcIdx = 187;
                    section.data(182).dtTransOffset = 269;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_ku
                    section.data(183).logicalSrcIdx = 188;
                    section.data(183).dtTransOffset = 270;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_k
                    section.data(184).logicalSrcIdx = 189;
                    section.data(184).dtTransOffset = 272;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_f
                    section.data(185).logicalSrcIdx = 190;
                    section.data(185).dtTransOffset = 273;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_j
                    section.data(186).logicalSrcIdx = 191;
                    section.data(186).dtTransOffset = 275;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_i
                    section.data(187).logicalSrcIdx = 192;
                    section.data(187).dtTransOffset = 276;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_m
                    section.data(188).logicalSrcIdx = 193;
                    section.data(188).dtTransOffset = 278;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_o
                    section.data(189).logicalSrcIdx = 194;
                    section.data(189).dtTransOffset = 279;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_k3
                    section.data(190).logicalSrcIdx = 195;
                    section.data(190).dtTransOffset = 281;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_e
                    section.data(191).logicalSrcIdx = 196;
                    section.data(191).dtTransOffset = 282;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_do
                    section.data(192).logicalSrcIdx = 197;
                    section.data(192).dtTransOffset = 284;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_l
                    section.data(193).logicalSrcIdx = 198;
                    section.data(193).dtTransOffset = 285;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_h
                    section.data(194).logicalSrcIdx = 199;
                    section.data(194).dtTransOffset = 287;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_k
                    section.data(195).logicalSrcIdx = 200;
                    section.data(195).dtTransOffset = 288;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_l
                    section.data(196).logicalSrcIdx = 201;
                    section.data(196).dtTransOffset = 290;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_ob
                    section.data(197).logicalSrcIdx = 202;
                    section.data(197).dtTransOffset = 291;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_i
                    section.data(198).logicalSrcIdx = 203;
                    section.data(198).dtTransOffset = 293;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_c
                    section.data(199).logicalSrcIdx = 204;
                    section.data(199).dtTransOffset = 294;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_k
                    section.data(200).logicalSrcIdx = 205;
                    section.data(200).dtTransOffset = 296;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_k
                    section.data(201).logicalSrcIdx = 206;
                    section.data(201).dtTransOffset = 297;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_nk
                    section.data(202).logicalSrcIdx = 207;
                    section.data(202).dtTransOffset = 299;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_i
                    section.data(203).logicalSrcIdx = 208;
                    section.data(203).dtTransOffset = 300;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_ld
                    section.data(204).logicalSrcIdx = 209;
                    section.data(204).dtTransOffset = 302;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_pa
                    section.data(205).logicalSrcIdx = 210;
                    section.data(205).dtTransOffset = 303;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_c
                    section.data(206).logicalSrcIdx = 211;
                    section.data(206).dtTransOffset = 305;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_o
                    section.data(207).logicalSrcIdx = 212;
                    section.data(207).dtTransOffset = 306;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_b
                    section.data(208).logicalSrcIdx = 213;
                    section.data(208).dtTransOffset = 308;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_f
                    section.data(209).logicalSrcIdx = 214;
                    section.data(209).dtTransOffset = 309;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_l
                    section.data(210).logicalSrcIdx = 215;
                    section.data(210).dtTransOffset = 311;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_f
                    section.data(211).logicalSrcIdx = 216;
                    section.data(211).dtTransOffset = 312;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_h
                    section.data(212).logicalSrcIdx = 217;
                    section.data(212).dtTransOffset = 314;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_k
                    section.data(213).logicalSrcIdx = 218;
                    section.data(213).dtTransOffset = 315;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_i
                    section.data(214).logicalSrcIdx = 219;
                    section.data(214).dtTransOffset = 317;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_j
                    section.data(215).logicalSrcIdx = 220;
                    section.data(215).dtTransOffset = 318;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_d
                    section.data(216).logicalSrcIdx = 221;
                    section.data(216).dtTransOffset = 320;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_m
                    section.data(217).logicalSrcIdx = 222;
                    section.data(217).dtTransOffset = 321;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_at
                    section.data(218).logicalSrcIdx = 223;
                    section.data(218).dtTransOffset = 323;

                    ;% Reference_model_Control_Engineering_4_P.Gain2_Gain_b
                    section.data(219).logicalSrcIdx = 224;
                    section.data(219).dtTransOffset = 324;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_g
                    section.data(220).logicalSrcIdx = 225;
                    section.data(220).dtTransOffset = 325;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P1_m
                    section.data(221).logicalSrcIdx = 226;
                    section.data(221).dtTransOffset = 327;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_l
                    section.data(222).logicalSrcIdx = 227;
                    section.data(222).dtTransOffset = 328;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P2_a
                    section.data(223).logicalSrcIdx = 228;
                    section.data(223).dtTransOffset = 330;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_i
                    section.data(224).logicalSrcIdx = 229;
                    section.data(224).dtTransOffset = 331;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P3_c
                    section.data(225).logicalSrcIdx = 230;
                    section.data(225).dtTransOffset = 333;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_n
                    section.data(226).logicalSrcIdx = 231;
                    section.data(226).dtTransOffset = 334;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P4_l
                    section.data(227).logicalSrcIdx = 232;
                    section.data(227).dtTransOffset = 336;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_ov
                    section.data(228).logicalSrcIdx = 233;
                    section.data(228).dtTransOffset = 337;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch_P5_n
                    section.data(229).logicalSrcIdx = 234;
                    section.data(229).dtTransOffset = 339;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_o
                    section.data(230).logicalSrcIdx = 235;
                    section.data(230).dtTransOffset = 340;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P1_m
                    section.data(231).logicalSrcIdx = 236;
                    section.data(231).dtTransOffset = 342;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_i
                    section.data(232).logicalSrcIdx = 237;
                    section.data(232).dtTransOffset = 343;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P2_c
                    section.data(233).logicalSrcIdx = 238;
                    section.data(233).dtTransOffset = 345;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_mn
                    section.data(234).logicalSrcIdx = 239;
                    section.data(234).dtTransOffset = 346;

                    ;% Reference_model_Control_Engineering_4_P.Dctleadlag_P3_d
                    section.data(235).logicalSrcIdx = 240;
                    section.data(235).dtTransOffset = 348;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_a
                    section.data(236).logicalSrcIdx = 241;
                    section.data(236).dtTransOffset = 349;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P1_m
                    section.data(237).logicalSrcIdx = 242;
                    section.data(237).dtTransOffset = 351;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_c2
                    section.data(238).logicalSrcIdx = 243;
                    section.data(238).dtTransOffset = 352;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P2_p
                    section.data(239).logicalSrcIdx = 244;
                    section.data(239).dtTransOffset = 354;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_o
                    section.data(240).logicalSrcIdx = 245;
                    section.data(240).dtTransOffset = 355;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P3_d
                    section.data(241).logicalSrcIdx = 246;
                    section.data(241).dtTransOffset = 357;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_d
                    section.data(242).logicalSrcIdx = 247;
                    section.data(242).dtTransOffset = 358;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P4_b
                    section.data(243).logicalSrcIdx = 248;
                    section.data(243).dtTransOffset = 360;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_ol
                    section.data(244).logicalSrcIdx = 249;
                    section.data(244).dtTransOffset = 361;

                    ;% Reference_model_Control_Engineering_4_P.Dctnotch2_P5_oh
                    section.data(245).logicalSrcIdx = 250;
                    section.data(245).dtTransOffset = 363;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_b
                    section.data(246).logicalSrcIdx = 251;
                    section.data(246).dtTransOffset = 364;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_f
                    section.data(247).logicalSrcIdx = 252;
                    section.data(247).dtTransOffset = 366;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_c
                    section.data(248).logicalSrcIdx = 253;
                    section.data(248).dtTransOffset = 367;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_o
                    section.data(249).logicalSrcIdx = 254;
                    section.data(249).dtTransOffset = 369;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_pk
                    section.data(250).logicalSrcIdx = 255;
                    section.data(250).dtTransOffset = 370;

                    ;% Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_lo
                    section.data(251).logicalSrcIdx = 256;
                    section.data(251).dtTransOffset = 372;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_j
                    section.data(252).logicalSrcIdx = 257;
                    section.data(252).dtTransOffset = 373;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_b
                    section.data(253).logicalSrcIdx = 258;
                    section.data(253).dtTransOffset = 375;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_d
                    section.data(254).logicalSrcIdx = 259;
                    section.data(254).dtTransOffset = 376;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_j
                    section.data(255).logicalSrcIdx = 260;
                    section.data(255).dtTransOffset = 378;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_p
                    section.data(256).logicalSrcIdx = 261;
                    section.data(256).dtTransOffset = 379;

                    ;% Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_o
                    section.data(257).logicalSrcIdx = 262;
                    section.data(257).dtTransOffset = 381;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 263;
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
        ;% Auto data (Reference_model_Control_Engineering_4_B)
        ;%
            section.nData     = 51;
            section.data(51)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_B.Startsetpoint
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_B.SFunction
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Reference_model_Control_Engineering_4_B.Quantizer1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_4_B.SFunction_b
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_4_B.ec_Ebox_o1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% Reference_model_Control_Engineering_4_B.ec_Ebox_o2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% Reference_model_Control_Engineering_4_B.ec_Ebox_o3
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% Reference_model_Control_Engineering_4_B.Sum
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 18;

                    ;% Reference_model_Control_Engineering_4_B.Buffer
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

                    ;% Reference_model_Control_Engineering_4_B.TmpSignalConversionAtToWorkspac
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 22;

                    ;% Reference_model_Control_Engineering_4_B.Constant1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 24;

                    ;% Reference_model_Control_Engineering_4_B.Gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 32;

                    ;% Reference_model_Control_Engineering_4_B.Gain5
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 34;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch8
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 35;

                    ;% Reference_model_Control_Engineering_4_B.Dctleadlag4
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 36;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch9
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 37;

                    ;% Reference_model_Control_Engineering_4_B.Dctdoubleintegrator4
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 38;

                    ;% Reference_model_Control_Engineering_4_B.Dct2lowpass4
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 39;

                    ;% Reference_model_Control_Engineering_4_B.Noise
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 40;

                    ;% Reference_model_Control_Engineering_4_B.Saturation
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 41;

                    ;% Reference_model_Control_Engineering_4_B.Gain2
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 43;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 44;

                    ;% Reference_model_Control_Engineering_4_B.Dctleadlag
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 45;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch2
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 46;

                    ;% Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 47;

                    ;% Reference_model_Control_Engineering_4_B.Dct2lowpass
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 48;

                    ;% Reference_model_Control_Engineering_4_B.Gain2_d
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 49;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch_c
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 50;

                    ;% Reference_model_Control_Engineering_4_B.Dctleadlag_g
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 51;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch2_n
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 52;

                    ;% Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_j
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 53;

                    ;% Reference_model_Control_Engineering_4_B.Dct2lowpass_a
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 54;

                    ;% Reference_model_Control_Engineering_4_B.Gain2_k
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 55;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch_p
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 56;

                    ;% Reference_model_Control_Engineering_4_B.Dctleadlag_a
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 57;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch2_m
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 58;

                    ;% Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_g
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 59;

                    ;% Reference_model_Control_Engineering_4_B.Dct2lowpass_b
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 60;

                    ;% Reference_model_Control_Engineering_4_B.Gain2_m
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 61;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch_m
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 62;

                    ;% Reference_model_Control_Engineering_4_B.Dctleadlag_n
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 63;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch2_c
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 64;

                    ;% Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_l
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 65;

                    ;% Reference_model_Control_Engineering_4_B.Dct2lowpass_a4
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 66;

                    ;% Reference_model_Control_Engineering_4_B.Gain2_kd
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 67;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch_d
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 68;

                    ;% Reference_model_Control_Engineering_4_B.Dctleadlag_i
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 69;

                    ;% Reference_model_Control_Engineering_4_B.Dctnotch2_k
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 70;

                    ;% Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_n
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 71;

                    ;% Reference_model_Control_Engineering_4_B.Dct2lowpass_j
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 72;

                    ;% Reference_model_Control_Engineering_4_B.Downsample
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 73;

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
        ;% Auto data (Reference_model_Control_Engineering_4_DW)
        ;%
            section.nData     = 34;
            section.data(34)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_DW.NextOutput
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Reference_model_Control_Engineering_4_DW.fileID
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Reference_model_Control_Engineering_4_DW.SFunction_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch8_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 55;

                    ;% Reference_model_Control_Engineering_4_DW.Dctleadlag4_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 59;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch9_RWORK
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 61;

                    ;% Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator4_RWORK
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 65;

                    ;% Reference_model_Control_Engineering_4_DW.Dct2lowpass4_RWORK
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 69;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 73;

                    ;% Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 77;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 79;

                    ;% Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 83;

                    ;% Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 87;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_e
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 91;

                    ;% Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_c
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 95;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_g
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 97;

                    ;% Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_n
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 101;

                    ;% Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_g
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 105;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_c
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 109;

                    ;% Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_g
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 113;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_o
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 115;

                    ;% Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_f
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 119;

                    ;% Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_m
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 123;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_o
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 127;

                    ;% Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_b
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 131;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_i
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 133;

                    ;% Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_k
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 137;

                    ;% Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_f
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 141;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_p
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 145;

                    ;% Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_m
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 149;

                    ;% Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_f
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 151;

                    ;% Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_m
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 155;

                    ;% Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_i
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 159;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.ToWorkspace_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_DW.Live_Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.RandSeed
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% Reference_model_Control_Engineering_4_DW.NS
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.NF
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.busy
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Reference_model_Control_Engineering_4_DW.eml_openfiles
                    section.data(1).logicalSrcIdx = 41;
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


    targMap.checksum0 = 3874783671;
    targMap.checksum1 = 1827489172;
    targMap.checksum2 = 3509571209;
    targMap.checksum3 = 89873337;

