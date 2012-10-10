#!/bin/bash - 
#===============================================================================
#
#          FILE:  scrip.sh
# 
#         USAGE:  ./scrip.sh 
# 
#   DESCRIPTION:  
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR:  (), 
#       COMPANY: 
#       CREATED: 10/02/2012 14:30:15 EDT
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

#!/bin/bash
#########################################################################
# Author: Yang
# Created Time: Tue Oct  2 14:30:15 2012
# File Name: scrip.sh
# Description: 
#########################################################################

rm data
make 2_grad_ecoli
./2_grad_ecoli >> data

