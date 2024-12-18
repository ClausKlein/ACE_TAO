#/bin/sh

set -e
set -u
set -x

#TODO: setup
# git clone https://github.com/DOCGroup/ACE_TAO.git
# cd ACE_TAO
# git clone https://github.com/DOCGroup/MPC.git

#TODO: sudo apt-get --yes install libxerces-c-dev libssl-dev

export ACE_ROOT=${PWD}/ACE
export TAO_ROOT=${PWD}/TAO
export MPC_ROOT=${PWD}/MPC
export INSTALL_PREFIX=/usr/local
####
export CC=`which gcc`
export CXX=`which g++`
platform_file='include $(ACE_ROOT)/include/makeinclude/platform_linux.GNU'
#TBD platform_file='include $(ACE_ROOT)/include/makeinclude/platform_linux_clang.GNU'

# create $ACE_ROOT/ace/config.h
echo '#include "ace/config-linux.h"' > ${ACE_ROOT}/ace/config.h

# create $ACE_ROOT/include/makeinclude/platform_macros.GNU
echo ${platform_file} > ${ACE_ROOT}/include/makeinclude/platform_macros.GNU
echo CCFLAGS+=-std=c++17 >> ${ACE_ROOT}/include/makeinclude/platform_macros.GNU

# Create $ACE_ROOT/bin/MakeProjectCreator/config/default.features
echo 'ipv6=1' > ${ACE_ROOT}/bin/MakeProjectCreator/config/default.features
echo 'xerces3=1' >> ${ACE_ROOT}/bin/MakeProjectCreator/config/default.features
echo 'ssl=1' >> ${ACE_ROOT}/bin/MakeProjectCreator/config/default.features
echo 'versioned_namespace=1' >> ${ACE_ROOT}/bin/MakeProjectCreator/config/default.features

# Run mwc.pl on $(TAO_ROOT)/TAO_ACE.mwc
perl ${ACE_ROOT}/bin/mwc.pl -type gnuace ${TAO_ROOT}/TAO_ACE.mwc -workers 6

# Run mwc.pl on $(TAO_ROOT)/tests/tests.mwc
perl ${ACE_ROOT}/bin/mwc.pl -type gnuace ${TAO_ROOT}/tests/tests.mwc -workers 6

# Run mwc.pl on $(TAO_ROOT)/tests/IDL_Test
perl ${ACE_ROOT}/bin/mwc.pl -type gnuace ${TAO_ROOT}/tests/IDL_Test -workers 6

# Build TAO_ACE project
make c++17=1 -j 6 -C ${TAO_ROOT}

# Build TAO/tests project
make c++17=1 -j 6 -C ${TAO_ROOT}/tests

# Build TAO/tests/IDL_Test project
make c++17=1 -j 6 -C ${TAO_ROOT}/tests/IDL_Test

#TODO: sudo -E make c++17=1 -j 6 -C ${TAO_ROOT} install
