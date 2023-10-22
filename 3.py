import pywifi
from pywifi import const,profile


wifi = pywifi.PyWiFi()

wifi_1 = wifi.interfaces()[0]
'''
wifi_1.disconnect()
target = pywifi.Profile()
while wifi_1.status() == const.IFACE_DISCONNECTED:

    target.ssid = '123'
    target.auth = const.AUTH_ALG_OPEN
    target.akm.append(const.AKM_TYPE_WPA2PSK)
    target.cipher = const.CIPHER_TYPE_CCMP
    target.password = 'wwb52155215'
    wifi_1.remove_all_network_profiles()
    tep_profile = wifi_1.add_network_profile(target)
    wifi_1.connect(tep_profile)
    if wifi_1.status() == const.IFACE_CONNECTED:
        print('y')
'''
wifi_1.scan()
print(wifi_1.scan_results)



