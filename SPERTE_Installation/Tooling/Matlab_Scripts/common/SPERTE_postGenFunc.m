function SPERTE_postGenFunc(modelName,buildInfo)
%% SPERTEpostGenFunc(buildInfo)
% Adds the EC lib to the linker flags
%
% WARNING - There is never a need to call this function yourself. It is
% automatically added when you use SPERTE_New_Model.m
% Through set_param(gcs,'PostCodeGenCommand','SPERTE_postGenFunc(h,buildInfo)');
%
% Input Arguments
% (required) h
% (required) buildInfo

% Copyright (C) 2021-2022 Enzo Evers, Max van Meer
% see www.enzoevers.nl for contact details
% 
% Control Systems Technology group
% Departement of Mechanical Engineering
% Eindhoven University of Technology
% 
% SPERTE is licensed under the GNU GPLv3

%%
%The following line used to be here without if statement, but since R2021b it only works if the
%codertarget.postCodeGenHookCommand is executed before calling this
%function, in the postgen callback
%Therefore, in hardware settings->Code Generation -> ... -> Post code
%generatoin command it needs to have:
% if (~verLessThan("matlab", "9.11")) codertarget.postCodeGenHookCommand(h);  SPERTE_postGenFunc(modelName, buildInfo); else; SPERTE_postGenFunc(h, buildInfo); end
if verLessThan('matlab', '9.11')
    codertarget.postCodeGenHookCommand(modelName)
end

%% Add ethercat compiler link flag 
linkFlags={'-lec'};

addLinkFlags(buildInfo,linkFlags);
