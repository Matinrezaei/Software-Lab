# prompt has been removed for easier Ctrl+C Ctrl+V
sudo ifconfig eno1:sxc 172.55.55.101 up # SPGW-C SXab interface
sudo ifconfig eno1:s5c 172.58.58.102 up # SGW-C S5S8 interface
sudo ifconfig eno1:p5c 172.58.58.101 up # PGW-C S5S8 interface
sudo ifconfig eno1:s11 172.16.1.104 up  # SGW-C S11 interface
INSTANCE=1
PREFIX='/usr/local/etc/oai'
sudo mkdir -m 0777 -p $PREFIX
cp ../../etc/spgw_c.conf  $PREFIX

declare -A SPGWC_CONF

SPGWC_CONF[@INSTANCE@]=$INSTANCE
SPGWC_CONF[@PREFIX@]=$PREFIX
SPGWC_CONF[@PID_DIRECTORY@]='/var/run'
SPGWC_CONF[@SGW_INTERFACE_NAME_FOR_S11@]='eno1:s11'
SPGWC_CONF[@SGW_INTERFACE_NAME_FOR_S5_S8_CP@]='eno1:s5c'
SPGWC_CONF[@PGW_INTERFACE_NAME_FOR_S5_S8_CP@]='eno1:p5c'
SPGWC_CONF[@PGW_INTERFACE_NAME_FOR_SX@]='eno1:sxc'
SPGWC_CONF[@DEFAULT_DNS_IPV4_ADDRESS@]='8.8.8.8'
SPGWC_CONF[@DEFAULT_DNS_SEC_IPV4_ADDRESS@]='4.4.4.4'

for K in "${!SPGWC_CONF[@]}"; do 
  egrep -lRZ "$K" $PREFIX | xargs -0 -l sed -i -e "s|$K|${SPGWC_CONF[$K]}|g"
  ret=$?;[[ ret -ne 0 ]] && echo "Tried to replace $K with ${SPGWC_CONF[$K]}"
done