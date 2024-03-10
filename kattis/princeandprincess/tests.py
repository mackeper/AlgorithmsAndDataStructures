from pathlib import Path
import random
from subprocess import Popen, PIPE
import os
import pyperclip
import unittest

class PrinceandprincessTests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\r\n', '\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    
    def test_princeandprincess(self) -> None:
        in_data = '''
1
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9
'''.strip()
        ans_data = '''
Case 1: 4
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)

#     def test2_princeandprincess(self) -> None:
#         in_data = '''
# 1
# 50 2500 2500
# 1 1914 2140 47 2160 2104 490 2499 2437 2190 1157 1973 169 1605 1524 1054 1421 567 819 1585 159 554 585 1637 767 1098 95 2134 1286 2329 1082 1718 199 407 1279 1744 2294 2330 454 102 2059 746 2338 438 1435 992 2374 1244 2302 2393 1760 1313 1426 870 855 1554 784 665 504 1458 713 976 769 537 1624 1192 2103 949 936 2371 2438 1000 1999 1205 1848 1217 1977 351 1471 1015 806 932 2090 594 1786 1568 909 411 731 316 1918 2429 1582 2366 2259 1252 2077 1930 50 1051 1942 1869 762 1729 2198 1032 886 636 2397 1502 1778 2126 1617 1598 956 1213 1314 1569 1309 1120 1419 2467 980 728 60 591 1227 1864 45 297 2378 2408 1287 546 2253 2078 1425 2235 2406 543 527 1613 2305 744 1589 2204 1468 2304 2209 2254 365 37 1337 924 952 1483 1877 1954 1344 1027 1211 287 505 2328 1704 523 2447 2312 299 1136 1058 857 1708 931 1162 642 1705 2472 2384 1272 846 1030 1733 1472 2495 370 327 1253 798 1111 1386 1289 444 2064 1086 389 2250 2223 1085 1985 501 27 785 529 356 1929 722 2129 2119 318 838 1373 373 1331 1255 770 1403 23 1552 824 1126 1798 2149 2016 1572 325 1398 2068 1857 423 1945 599 183 1071 2075 268 2275 2390 1793 1812 1980 1004 1464 97 2452 2154 1692 1656 1166 2096 1742 847 1876 2182 1433 2130 1140 2405 349 1643 557 2161 168 2342 1693 1066 2414 1119 1456 893 1320 1209 234 1512 1906 2201 2164 608 2114 578 1104 1852 525 2451 2273 1722 1445 1475 654 313 1224 664 453 1128 2117 1053 1610 558 1541 1315 43 640 748 597 1779 162 2052 1395 651 1991 139 703 2267 1696 271 1535 2317 2458 668 186 1938 1134 35 859 1933 1989 720 677 1005 1770 184 735 1242 1438 662 1671 1936 1256 2339 573 1092 1900 1199 1519 533 2284 96 408 1003 1833 1932 690 959 1201 1862 934 1448 1377 882 1984 1508 733 1001 321 2005 1143 174 1360 255 1170 1449 2212 1228 213 1810 1898 1801 1148 1374 9 2229 1863 167 471 157 1333 1036 715 568 1379 1739 2324 814 1273 2216 418 367 1156 1292 2040 101 14 1174 530 1949 1424 1372 20 241 2255 341 154 1269 160 1137 994 818 679 1163 2025 7 148 2044 163 587 2292 1672 1147 2033 2347 1311 1599 717 862 875 948 2034 1072 1480 1138 1935 791 678 237 1303 2012 1278 883 2128 1709 119 2425 2014 1436 87 53 1794 399 1586 706 2367 2411 309 2029 825 1155 1842 1995 2382 1788 1057 1165 1885 1836 1919 750 2093 1745 2468 610 1159 1007 2279 1974 1362 2435 1487 1544 1288 550 1689 1149 2445 632 105 390 1326 1654 1882 811 1068 743 1507 1110 1965 2108 751 2132 2000 103 276 388 2009 30 1520 1257 1100 637 2171 2357 1664 2496 417 795 1686 1641 1969 1813 1879 541 1622 1375 230 1678 1245 152 729 563 2242 1194 2106 72 2156 2277 2069 1277 680 1383 1587 301 1602 483 984 1928 3 646 258 1961 856 782 283 955 1827 2365 289 1831 1018 455 2462 1200 836 2423 1250 756 1510 2116 708 2334 860 1843 2287 1996 1904 634 41 779 2112 648 829 2477 434 1422 1566 203 1034 929 2434 2464 650 2111 1771 711 2283 42 2199 2276 1698 436 638 2337 1106 1690 1758 1074 903 1982 1768 326 2349 2401 643 1623 508 623 1941 712 1948 1662 281 238 2427 2073 253 775 1144 1345 2045 754 1504 1986 741 626 1220 653 1469 91 1983 596 628 2313 1064 1240 1350 1645 2023 1484 445 2379 2311 1993 2244 1815 894 895 669 1746 1359 278 179 265 1584 2368 1181 1792 1646 1988 2241 2037 786 778 1707 2281 1107 2063 516 1282 656 1628 845 2336 1130 1668 393 1141 1399 220 350 1285 2043 2432 986 1630 270 1751 1342 1604 1762 76 293 2072 2071 277 201 2280 1518 269 999 2386 1597 1868 796 813 2133 2363 1232 2178 820 247 671 394 2440 2176 1195 343 1818 311 2213 1019 842 358 1059 513 1581 470 1154 1717 967 376 205 1575 1950 1216 2248 1776 1503 1189 912 1122 1884 1332 1447 2227 1902 263 2061 1117 2074 1439 22 2017 776 800 1465 1960 392 1522 93 2356 757 71 323 1348 1423 2022 1728 106 887 1183 366 1476 2086 1016 1850 2453 1158 2032 79 141 2474 458 412 2391 1712 2436 345 208 1633 1115 696 2301 699 355 1607 1578 460 1369 2097 1669 337 1236 682 2115 262 534 2224 889 1251 1356 759 1903 1496 574 1187 1327 1543 2257 1490 1595 2028 377 1509 799 1301 2147 884 415 771 987 2137 1860 182 1176 606 613 5 2067 1246 670 1123 1682 1321 68 1207 1172 539 1459 612 465 2214 1109 386 2136 926 437 1532 2019 1397 2189 2278 1683 719 194 918 880 346 153 1169 1033 2262 2327 964 196 476 2095 1800 2120 21 1180 2333 401 36 1912 910 1822 1953 73 146 1178 1020 223 1198 1558 1853 1304 921 625 302 1804 1811 1652 378 817 506 468 584 1002 1407 1197 1806 1463 1338 707 1084 158 88 803 1492 906 2220 2222 1601 166 178 2491 116 2026 989 1367 2323 1737 1262 850 1614 1769 807 496 1839 1925 233 462 1323 433 1160 1871 512 1859 442 2211 66 46 1239 315 211 371 1312 1305 2083 226 1249 2497 273 1501 2482 761 1026 61 1416 1775 77 1854 463 2206 191 1336 630 1952 2316 272 1482 2070 344 1910 1759 133 2299 2353 1056 892 1574 1894 2191 997 1621 622 1173 294 714 2343 660 962 280 1889 2443 1093 1376 2173 1241 2135 1924 2321 406 899 2354 577 851 1324 502 1755 244 2041 151 2217 2381 2099 755 588 810 2332 1455 235 1845 430 1440 590 881 135 1616 1694 607 1339 215 1365 1626 1947 1916 644 1911 1022 1814 1609 2219 1366 1427 739 207 990 1657 1796 1734 1832 618 592 2020 2476 1062 336 1908 601 239 1738 954 360 1618 521 2251 52 2493 2260 2306 2057 572 1055 661 916 8 805 514 2051 1274 1415 131 1890 317 452 1726 1363 122 547 1979 985 1452 1743 915 1310 2446 1493 1206 555 792 2172 2203 1418 324 616 695 535 566 28 1741 1035 2249 449 1515 2300 1747 2155 1963 914 1655 1531 1188 1185 1795 1867 259 250 2180 19 1907 260 834 2100 1875 1887 2484 1385 2079 974 2247 427 2483 1546 752 1921 1861 1872 12 663 605 1557 74 1328 1866 86 1873 1714 928 1934 111 1588 1042 1184 312 1210 1650 790 1378 991 134 1267 1127 1043 472 1536 214 2004 1802 745 16 1329 1095 1380 1473 1434 692 2186 600 2091 332 1529 911 32 2225 2143 1012 536 1347 768 1291 890 1987 1391 1748 1560 1612 2168 353 2487 2205 254 698 526 352 933 1387 70 685 26 69 228 1413 2290 553 510 138 1266 303 872 919 2479 826 540 833 2286 2410 1858 17 1823 2087 2419 1225 2258 1992 1479 853 2322 1293 888 981 421 1539 687 2192 1125 1528 1045 1571 1855 1177 704 2473 1923 1847 2002 144 2465 1212 1299 39 710 1724 149 2298 998 1124 864 1799 1358 2456 874 1838 1218 1590 2461 2494 2027 877 969 1094 1271 396 1457 891 1499 1409 143 562 943 2181 2444 225 1101 843 2274 571 773 1222 1966 548 1644 2047 62 398 165 2413 2269 1392 725 1182 67 1325 387 1821 1099 2049 1540 1260 1706 381 576 498 1927 873 2350 2389 520 511 2340 923 63 2001 1970 1567 473 1235 579 675 1505 209 1547 581 655 285 758 1388 431 723 2151 89 2439 410 229 1114 1713 2092 1167 777 2105 1237 2256 286 2170 659 1097 564 978 1179 1750 2124 1486 545 1715 1444 1651 832 1461 1880 1562 1774 1221 54 1268 57 2228 1298 801 2157 55 975 1430 2081 2370 1816 202 222 212 120 2233 793 1091 1078 1659 1021 99 815 307 1673 950 1851 1202 673 2236 413 2053 267 2046 347 1826 2094 1371 1780 364 1006 917 1881 503 1684 740 1404 1819 1153 1625 2101 1396 1261 2175 261 2454 945 2385 2264 1828 187 291 1723 2169 1453 968 1017 1538 1577 2218 2202 1474 2084 1691 2310 2179 1548 1302 1639 1352 1797 1208 2011 2162 108 340 180 1685 1702 1406 150 1893 422 1511 1382 1491 913 1013 282 457 1761 1803 2042 98 1958 1276 1164 333 305 161 868 1550 251 481 1865 879 435 1414 236 1024 724 876 1635 2288 1870 2490 232 2364 185 1113 485 44 2183 362 1103 1500 1089 1384 1105 2266 2185 1767 284 170 477 1076 995 1817 84 830 658 1351 816 176 1611 2308 718 2232 1756 304 822 1322 1073 705 479 1214 375 1316 1834 789 428 569 2013 854 310 322 528 780 509 797 1161 2404 1667 2008 2373 243 1642 1790 753 1116 823 2325 145 2398 1243 2239 1341 82 137 1112 221 666 1297 1899 1401 127 2018 2146 31 467 48 1697 942 446 488 330 1926 1553 869 2089 2489 2237 1254 1412 1699 1809 2215 1972 2122 2359 721 129 1355 1764 357 1681 804 484 1701 2486 896 560 397 2412 2375 308 1488 542 1238 1897 2272 1090 517 409 1757 766 960 2463 2245 295 1428 1856 1888 865 1997 973 1917 2150 961 1437 1219 925 1564 1131 993 493 1700 1665 2344 681 2231 416 1730 1308 1441 1142 2399 2082 1534 1964 486 1495 2060 1247 1364 2303 935 947 1570 922 2080 2289 1460 2177 957 982 1670 342 1647 674 1766 2036 1530 1411 1295 124 1517 480 1629 2395 2297 1620 2407 2153 252 617 966 1041 972 742 1660 126 361 2417 1040 264 1478 348 113 1290 970 1829 1840 515 1361 2123 2450 2031 2466 1497 117 1470 518 248 1223 1506 29 629 2207 1038 1878 649 1306 1703 1389 2420 1632 495 1402 1275 2050 2113 841 2163 565 631 1901 1196 702 1467 1727 1937 2416 1765 953 489 2148 1592 1168 1462 1631 328 1943 2193 1061 885 1740 652 1753 497 1102 996 1451 927 426 930 142 2358 1294 2441 1754 2263 1405 1335 686 2066 395 774 25 1146 1573 737 1551 246 1971 598 2030 6 2442 694 1634 363 988 1135 2007 667 709 319 245 1052 1477 1248 1060 13 1580 609 206 1648 474 500 1951 2455 871 2433 1129 1721 831 2426 1346 783 49 482 487 1229 1354 2265 1593 384 2006 1226 383 1957 688 2076 2430 296 828 200 1946 2383 104 580 491 123 1915 1394 1849 51 2345 164 639 2024 2261 2492 499 405 627 492 2478 359 1264 300 1039 1420 2396 443 2361 1307 1735 1283 727 1087 604 1716 1627 1896 905 2481 2318 2403 1606 1959 217 635 2295 1752 1175 944 971 2422 466 2035 2307 1636 2159 937 1070 2400 461 570 382 181 204 112 1429 1719 275 983 334 2488 802 522 1280 338 1824 1615 2369 1171 380 940 2471 531 1031 1998 2221 764 1454 118 1895 858 938 866 1150 1976 1317 2226 979 469 94 1661 2167 1710 1393 603 620 1048 404 2418 391 1075 354 1481 2319 190 372 1830 1263 1772 114 197 2174 808 1215 1489 1191 1565 1680 701 1334 1357 734 65 1820 2062 693 132 1118 641 2187 1679 697 10 602 2387 224 1485 257 121 2331 216 1513 1736 2460 1526 657 583 1720 1023 1186 1783 611 369 38 716 447 2348 24 231 621 385 188 1591 1190 2139 1025 2109 2131 2415 1711 2184 1576 2021 1133 1676 861 2208 249 1330 1029 1649 292 1603 1653 2448 1891 2165 507 1318 90 1807 414 459 335 1417 4 1805 2388 760 1892 2475 2293 1608 1281 1545 941 1688 425 1808 1233 92 1990 1994 1296 1014 2457 1259 738 2243 2 306 732 1083 837 320 2470 298 1446 1050 125 1666 1230 1563 849 2377 1079 848 2282 2127 1521 1063 1204 58 1400 1968 907 2197 1234 1905 2144 898 1381 2459 2360 2118 839 80 189 439 2409 192 1527 2376 1088 2498 2469 136 1096 1450 863 1523 1677 2230 2341 552 844 852 2039 2234 2210 140 2098 1791 2270 2449 266 1846 821 2380 763 1763 450 1782 193 1594 1825 1931 1065 2056 1069 290 2431 331 1978 1514 736 1044 1028 494 749 2102 1432 772 2003 1152 556 544 2107 78 451 809 1525 1909 1944 946 2121 130 1579 419 33 920 40 2200 684 2326 1139 2291 107 593 1920 551 1037 1785 645 689 1431 2055 691 1049 1077 2351 274 1975 59 2362 1675 633 1874 2088 1841 2271 2402 559 1443 532 456 1781 128 1533 1121 647 1145 429 2138 700 177 424 2252 672 582 1193 171 730 1408 1913 219 908 1343 279 963 1231 958 1258 1047 904 475 1939 1640 1725 2320 2315 256 147 2238 2355 288 2015 1368 615 575 2268 240 1837 1009 1777 2352 1940 1494 75 1132 81 1784 156 1011 1600 788 2485 1956 2141 440 1542 464 827 85 781 1300 1835 1773 977 420 1516 2424 2394 1731 867 1010 2296 1663 1962 965 34 210 619 2125 2110 1410 794 368 1284 2309 2335 765 2314 2246 2058 2392 2428 835 2372 402 901 2166 15 614 400 441 1498 1955 448 173 1151 379 1353 2285 1787 2065 195 1046 1967 2188 1619 1081 1561 519 478 1108 1658 1583 110 1265 1349 2240 2196 1886 586 897 329 1981 2048 1844 83 951 1922 2085 2421 524 1883 1695 549 1749 1466 1556 314 1596 787 2195 2346 172 900 115 1067 198 1008 840 561 109 1559 726 2158 589 242 1549 56 538 2480 2038 1674 155 1555 812 432 374 1638 1789 18 2145 939 1732 1203 1340 175 218 11 403 1080 64 624 902 683 595 2142 1687 747 676 1442 2194 339 1537 227 1390 2152 1319 1270 2010 1370 100 2054 878 2500
# 1 112 516 538 2052 2086 397 1867 220 1325 497 2223 2464 2047 1616 1537 73 2283 743 1573 873 529 1979 1470 2483 1272 473 530 1313 341 2436 726 1357 1025 1758 1431 1635 702 2041 503 2475 633 562 257 1876 1068 866 984 2458 1463 1188 922 2332 434 410 353 1258 2147 656 2407 1555 267 1678 2453 788 436 1160 1408 632 412 963 1659 1911 414 1296 164 2302 909 745 1181 2180 528 766 345 81 1266 1063 795 1280 1083 731 2319 1493 2442 2259 1165 176 300 2097 1562 693 793 1136 1507 786 1387 1730 1662 1768 2188 136 2346 774 713 42 1785 1800 1448 461 2176 598 1783 1693 1388 404 697 1914 172 1847 1927 302 1193 254 278 225 1634 901 393 1268 2251 379 2211 475 1132 1667 542 712 981 2463 2299 88 957 2112 1856 1496 2006 93 2167 813 1282 835 53 344 1071 310 1269 1834 2190 904 1380 2141 746 1464 223 1336 1657 1436 185 2378 1017 1178 1632 1641 2135 217 1130 1919 80 2389 134 1526 85 199 641 773 1225 554 1941 1311 241 789 27 1755 1722 2368 931 1439 2457 1260 1718 1329 998 2128 1655 1825 1016 1639 476 851 2159 1447 2446 1113 2418 2297 170 603 2121 1666 1749 534 230 2305 1501 2405 2218 994 1949 1244 2285 682 1650 2100 1614 975 574 748 2003 1022 2151 652 1365 383 2384 1767 1959 178 1965 1462 848 1590 290 1519 1934 2049 1302 536 474 2229 850 1910 544 1692 373 1674 1118 387 1166 1180 556 2447 1122 484 561 2247 2312 1495 2185 858 567 2428 236 1811 952 512 2142 737 1846 10 870 570 671 1422 2182 1955 599 611 2467 1500 1600 2331 584 1759 1920 1921 509 407 869 993 430 1683 281 1356 1418 1353 1001 1854 1521 1916 2334 576 355 1110 150 406 2156 1993 892 1233 1962 2166 658 2072 1421 744 2295 197 934 708 1309 37 2496 99 2265 855 482 159 1559 2403 1636 1133 447 1807 491 1977 1786 1111 810 1865 800 690 1172 1538 956 1936 1923 2221 1750 246 352 1317 2399 1326 2487 1089 1382 1874 1235 1617 877 717 1460 2400 1843 2298 1433 1481 2465 815 1822 5 1687 391 1734 2429 1547 1229 1523 2482 429 1397 2380 1443 2195 1838 1582 1392 1764 1333 1051 1697 1257 913 1170 304 1404 1145 203 807 1801 1980 513 2433 428 128 1032 365 1624 483 2034 1008 797 1886 262 2383 1583 124 2413 2136 1818 151 1896 1545 2191 1399 772 215 988 1673 1625 527 1354 349 646 1816 2311 1898 2304 1938 1378 1571 2127 2103 1212 525 1810 413 1769 2149 837 749 2342 1592 1594 891 2132 1200 1255 1451 1909 2016 2183 1948 822 1999 1556 615 2011 1286 1715 401 2193 1837 1913 1775 1103 4 8 1950 705 2480 286 440 32 2360 1348 1513 1511 1664 1227 2184 2118 463 2157 756 2347 1862 207 605 628 2224 923 1424 1684 1222 2111 1970 366 33 1426 1402 469 2015 814 354 1498 1323 2105 1539 2386 1330 39 295 1845 1270 1680 2335 908 2071 1073 997 2352 1844 1663 2494 362 1587 1964 601 1917 2215 2102 874 1883 1642 558 709 2266 2233 2404 2323 1018 1599 396 834 1045 86 1190 790 2070 157 500 1557 2237 1512 1087 471 1486 2226 1490 531 2022 1515 1461 107 2150 2120 1245 102 1250 279 265 273 1689 2396 1279 2250 969 1570 2275 879 1377 857 1450 987 2406 2329 69 802 2217 1963 751 872 587 974 1610 1489 1626 1060 1905 557 2061 506 824 679 944 2444 1589 573 492 1607 451 2408 96 1741 2205 1364 912 1444 543 2146 2394 966 2366 1560 1029 2001 2290 1532 1901 405 1039 964 1606 1480 2014 342 2317 592 260 2082 734 582 2088 1234 1752 376 2025 1080 1812 2117 2484 1935 867 2333 402 626 116 320 510 30 1221 597 1351 2476 581 1671 1762 1238 2172 806 425 2145 460 2008 1403 2361 2181 1174 669 210 1070 683 1819 618 6 2000 595 1367 778 2314 2416 2375 2445 138 2063 519 1289 2337 462 36 2270 2306 871 1031 258 1708 1374 2301 2328 2421 2164 1064 2065 1415 1784 657 498 1085 211 990 1502 2293 1468 2461 2488 2425 360 767 1790 811 1102 1880 2089 1745 1466 75 1640 2466 1427 539 228 2271 1277 1974 1432 792 943 1041 1058 2154 881 540 1033 1860 921 1000 1096 763 455 2294 940 423 1703 761 1156 2148 2161 1516 1622 992 403 1003 738 47 2391 664 2449 1814 2252 301 1300 762 472 799 1726 1575 1391 1670 1884 1652 277 50 308 707 735 317 896 417 1499 553 1975 1477 195 1362 1196 805 1023 1997 408 1633 1611 283 1677 588 173 208 427 1593 1187 2194 521 2168 2441 1218 1220 1340 1598 1895 1738 2144 1864 227 443 336 1766 700 1485 2364 902 1517 222 1203 313 983 161 1946 1591 84 224 844 666 13 1207 34 2045 1748 2080 1106 887 1239 759 1875 1824 1124 1411 2018 250 1332 1219 1369 1384 350 135 139 936 1131 577 722 1128 1449 52 1798 287 282 1082 1393 619 2256 2427 2455 765 1176 54 1090 2009 90 1077 1780 776 2343 2002 368 285 1618 256 1543 28 214 760 218 325 1056 3 384 117 196 183 733 1968 2348 1050 2099 826 982 1581 832 2131 2261 488 1944 1529 129 1042 937 1580 1924 1952 1143 1004 1138 431 565 1841 1352 1135 740 2028 617 1996 1535 1355 1747 1308 1321 268 863 1406 1206 1714 1577 650 1441 2173 2369 2279 1191 676 2309 2472 505 1978 1030 915 1099 2076 890 1628 820 2004 1005 1162 421 564 941 1314 754 2241 141 634 1028 1542 2046 399 209 1566 1320 1848 1638 1890 526 2204 2200 1644 2234 918 2029 1497 662 1446 1293 386 753 356 2098 684 1154 999 2219 1049 1491 1442 133 1773 1216 583 636 2477 1360 101 1757 949 2374 893 1823 637 1928 688 2060 1549 1586 842 2177 2169 2106 2438 2357 2423 61 1623 991 951 2104 2067 1109 324 1247 961 2026 1067 804 433 2417 2263 549 1704 1613 2426 680 1863 2059 92 546 784 2051 1161 1020 17 2277 886 1208 1140 2355 190 1771 849 675 1569 2498 1973 1115 1194 948 1437 2054 572 499 1366 878 2435 2432 315 109 1310 1469 1681 251 794 306 1615 1413 884 1373 853 422 1861 1897 1688 155 1027 1405 2489 1043 1832 160 213 2035 1951 1104 711 876 2330 1141 518 1887 2056 2203 2434 1550 1119 26 2081 2387 480 569 180 1276 1316 1603 1710 1778 2338 925 1698 875 678 1869 2210 420 859 2123 103 94 2468 1092 348 1395 275 2187 2448 2171 255 507 2212 1294 2282 2497 118 147 194 1412 1889 594 1214 1036 1195 188 1211 689 1713 77 548 2036 2039 204 1899 299 1148 2248 2163 1653 2013 2321 15 1893 1142 2249 714 79 1872 1318 1522 437 2158 2359 742 2262 1877 894 59 840 1129 607 692 843 181 40 1908 1456 2471 2409 389 903 442 833 426 2451 979 723 1540 2122 253 229 575 1079 309 2186 1117 1236 62 655 2007 1398 338 2316 119 1719 687 768 2012 243 1224 959 2017 888 1159 458 775 933 2133 43 727 1998 2162 239 2410 586 1953 121 910 385 323 1903 2320 977 2155 163 1386 146 390 967 1091 41 1649 1528 1487 1701 927 622 2393 1732 624 1062 2208 635 911 307 1992 1231 1175 701 698 808 2096 1972 2269 2280 1061 1596 1084 1440 346 780 1826 2225 2327 716 1376 648 12 838 1337 1215 245 2239 703 2362 920 1455 2243 1205 640 1799 2214 1169 111 724 2473 1361 1291 2078 1554 70 914 1551 234 514 777 249 1756 1721 670 435 1186 1137 504 882 261 696 1648 2213 1471 660 677 381 1349 98 1839 1676 242 2354 201 9 827 2170 2456 1295 1350 212 276 590 846 1508 192 1739 23 520 1770 2031 22 616 314 1107 1370 1836 825 1643 1871 165 51 55 1728 175 1459 2372 1287 1120 2460 1915 1506 860 1046 1184 2083 2242 728 411 547 545 202 479 2481 456 502 167 1126 1076 1044 1048 1429 1754 1842 1482 770 1146 2050 2257 1095 1685 1416 1788 1969 704 1966 2303 623 478 1866 35 614 1331 2240 184 339 2175 464 1983 29 739 1878 1690 1134 2198 1533 1040 1813 1645 720 791 1453 186 152 409 985 568 1534 154 400 972 120 2209 1568 563 691 1712 2345 1945 1341 2101 839 1014 266 238 1479 2424 331 1504 1210 1631 1420 2365 865 2037 2499 2267 19 1065 367 221 1328 1597 372 2138 818 880 1525 1716 1261 1947 1334 2038 1548 419 2281 1808 1976 263 1298 1163 1852 1312 1167 695 694 699 1150 935 1753 1572 1121 2358 364 1274 1074 2253 1478 1821 2478 1700 1840 2260 2092 1520 2235 100 2367 316 2085 1452 1849 1262 533 1248 1458 1530 1335 2053 1957 2206 2178 424 1338 166 515 1627 2220 1731 2068 1661 438 1939 2042 2095 1787 1518 450 2196 816 1228 1789 2254 1385 1763 883 7 1359 1509 2062 122 1010 2174 1857 24 2019 439 2152 2388 2397 2074 651 537 357 67 970 836 821 2010 950 1400 21 189 1552 2032 1002 1900 1740 612 1746 1904 1942 2324 2420 1201 2258 1182 1253 1259 1588 2414 2398 629 468 1932 2245 596 928 1699 895 219 917 1198 1578 60 1125 1922 511 206 271 2490 1735 1457 2462 2382 1660 854 1267 823 958 1249 467 25 454 1608 668 1971 1675 2055 747 579 1803 2073 1894 1918 2216 1114 962 1078 2005 2356 244 954 14 2090 395 1565 2310 1177 1445 274 898 1795 1981 1322 2495 123 2325 779 2255 1742 919 729 608 905 1151 1621 1199 1995 719 2064 1835 446 1541 394 757 1960 1881 602 1473 812 449 642 673 732 1241 1984 2107 1696 2030 1307 829 620 613 1168 2023 852 2268 649 847 1242 343 1546 1668 1407 322 803 477 369 1494 156 289 736 83 1414 1105 2227 327 259 2137 1833 621 1760 2292 226 1139 1256 1619 1053 965 2066 1858 2430 1423 49 297 2339 2390 303 2021 580 272 270 1679 145 721 600 466 2075 496 378 1094 44 1851 2130 1564 174 1112 1931 769 1410 1879 1252 1088 1882 1072 1776 2246 585 1682 1527 1991 659 2020 1434 1906 293 57 978 787 1647 2474 897 127 1327 2431 18 1100 328 667 631 1054 1815 1907 1576 1454 1956 237 2125 1723 2207 2470 1743 899 2091 1438 1595 398 571 2353 298 495 2199 1379 264 532 441 1155 2274 1012 1319 1737 490 718 1695 1912 1604 457 1389 798 72 2094 335 1711 2179 132 2395 198 2454 415 665 494 645 681 2115 1827 1725 388 1994 926 1985 630 1059 989 1629 1475 1986 856 609 1173 481 2244 46 2486 663 1013 312 606 2160 968 1394 1868 20 2493 375 930 591 2289 2371 1202 1892 1116 493 1343 1007 171 340 1192 71 453 2307 448 177 76 2422 752 87 329 2276 1339 2287 550 1254 1853 2308 1232 1831 1285 382 2439 1183 140 862 639 783 889 1751 1706 1425 1926 108 1665 2286 1158 2230 144 280 2402 1021 1243 938 2340 1278 501 1011 1273 647 1246 321 644 380 1601 330 2 1925 1283 1656 1342 1372 216 610 1101 1930 1553 131 470 1567 1503 764 1009 337 82 1809 559 782 233 1804 1474 1558 2108 142 292 1358 1989 2415 1075 162 2479 1781 1630 1306 2401 1347 995 2318 1345 11 2134 2057 715 2024 1744 1488 864 2232 523 2469 1209 1057 1967 2272 929 1669 288 89 91 2119 1417 1705 248 2411 1275 1483 1019 750 1794 2385 2351 2350 2296 1733 16 868 1324 1037 1536 1428 796 1223 2412 126 1299 149 1301 2084 643 2322 269 1620 2079 758 1396 2492 942 1820 2313 1694 1584 38 1765 2192 1672 1197 105 861 358 1467 2153 1157 1561 374 193 200 294 1153 653 1492 2370 1958 2143 1651 485 2197 2044 232 1152 158 1987 2273 1637 143 1805 2202 2124 1265 1147 1052 2288 2452 2443 741 1605 1098 2336 2033 1066 522 1802 66 371 1288 2222 1828 625 319 392 508 986 1237 1401 2377 1055 674 524 291 1284 1612 2450 1691 1929 755 333 578 334 1035 284 1724 1829 638 78 1792 2165 104 661 1646 2459 2344 2300 1830 1870 2077 1885 801 1961 1817 2087 551 1047 1472 1015 1602 1230 1204 169 2058 953 1435 819 332 809 1024 1772 593 1727 1346 560 1531 1510 960 1791 179 916 1189 432 725 1240 1563 1304 654 1213 1544 2027 1217 45 947 924 137 541 1990 305 771 247 1891 235 976 900 1281 706 1729 1779 781 1290 1888 1579 1933 252 730 1263 205 1943 2376 148 1390 48 1782 2040 1371 347 2201 359 74 906 65 2114 487 1982 1902 1292 945 1654 1796 1381 1409 370 1609 1585 2349 1736 1297 110 980 2392 2189 2379 1855 64 885 1149 153 1658 191 1086 1686 187 486 445 2048 182 1793 1937 318 1368 831 817 2109 555 2437 1873 1271 2113 113 1164 1806 125 2140 1465 2236 363 377 1251 710 2485 1026 2238 459 996 489 58 1363 444 2093 1777 1038 1954 2419 1171 2284 841 130 627 672 1123 1720 1144 2315 1375 1305 2326 2278 955 240 1185 1108 830 1383 686 845 1093 2228 296 1476 973 2381 1419 231 452 2069 97 785 418 685 106 828 604 517 95 1514 1226 351 2139 1988 1097 465 1774 63 416 168 1761 1264 2129 1315 1081 589 1717 1574 1484 2231 932 1859 31 1797 1850 1034 1303 1344 68 2116 1127 1702 114 939 2110 1524 1069 2291 566 535 56 552 1940 2126 2440 1709 311 907 115 326 2341 946 1505 1707 1430 1006 2373 361 2043 1179 2363 2491 971 2264 2500
# '''.strip()
#         ans_data = '''
# Case 1: 12
# '''.strip()
#         result = self._run_test_file(in_data)
#         self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)
if __name__ == '__main__':
    unittest.main()