import os
import random
num = int(input("Enter you range : "))
numbers = random.sample(range(-10*num, 10 * num), num)
#numbers = random.sample(range(10 * num), num)
#numbers = [2153, 3282, 2278, 1655, 1200, 3329, 1050, 2520, 514, 4527, 1450, 761, 3052, 4368, 2597, 4913, 2308, 1333, 4920, 3976, 4251, 1121, 4605, 1733, 3278, 1794, 3481, 3594, 2201, 3690, 2725, 212, 1363, 1981, 1576, 3811, 3031, 3254, 167, 4209, 2636, 1425, 2160, 4062, 4179, 1186, 3663, 1128, 781, 4265, 632, 4424, 3946, 1608, 3801, 703, 1903, 4619, 2973, 1181, 2867, 4507, 2778, 4348, 1881, 1346, 97, 1650, 4535, 1279, 834, 1103, 4795, 4274, 106, 3611, 1672, 1295, 2801, 4512, 1242, 3808, 3948, 2594, 1523, 889, 34, 2507, 3933, 3494, 2241, 79, 1542, 982, 2818, 2872, 4021, 1285, 4968, 2370, 610, 2548, 4955, 2858, 3029, 2181, 4010, 3067, 3431, 4312, 384, 727, 2556, 1521, 3513, 3561, 4176, 3981, 2596, 3817, 4912, 3034, 3816, 688, 1870, 2921, 436, 1563, 3310, 4868, 1313, 2344, 4299, 4232, 2271, 4340, 4850, 2775, 3912, 2971, 4728, 1100, 1710, 4323, 3143, 1638, 4433, 66, 996, 2804, 241, 2614, 3995, 4828, 2752, 1129, 3911, 662, 878, 1224, 3822, 1876, 2292, 3797, 3370, 1421, 15, 304, 2598, 3022, 112, 550, 3671, 4353, 136, 1761, 4927, 1701, 826, 4517, 3573, 2378, 2282, 2348, 1231, 732, 4917, 1811, 3576, 1327, 1553, 1782, 2038, 3548, 1189, 3538, 1893, 4440, 770, 737, 1751, 3229, 4820, 1508, 1140, 2795, 2280, 3786, 3371, 1610, 4355, 4668, 1829, 1340, 3219, 2338, 4342, 309, 4164, 2855, 1937, 4789, 1684, 4915, 3202, 3269, 561, 2688, 1720, 1350, 2542, 4078, 2265, 3625, 2381, 3126, 3767, 3405, 874, 4374, 2608, 903, 3286, 731, 3880, 317, 1391, 3357, 2612, 1843, 2463, 1010, 2830, 4442, 998, 1472, 4395, 1885, 1520, 4407, 105, 1716, 3021, 2200, 22, 156, 3656, 2183, 1252, 1006, 2868, 57, 633, 3107, 1605, 4844, 627, 3113, 1367, 935, 1651, 2281, 1001, 3996, 2116, 3062, 1919, 360, 1301, 778, 4660, 2329, 3720, 1547, 721, 1715, 60, 3708, 4061, 3424, 4228, 3439, 2286, 2659, 1661, 1069, 3133, 4644, 4905, 1557, 2313, 1731, 4961, 1998, 2485, 3188, 763, 4878, 2772, 4466, 2631, 4463, 342, 1844, 2070, 855, 2411, 454, 4482, 1057, 641, 2425, 2305, 2430, 1522, 225, 671, 4570, 4518, 3496, 1518, 3534, 2508, 4092, 3103, 546, 3498, 1447, 3468, 3986, 1790, 230, 4586, 1321, 1960, 2252, 657, 2210, 427, 4887, 3858, 3953, 3877, 930, 4656, 3096, 2840, 3843, 4187, 1469, 2155, 3410, 967, 3091, 274, 99, 1837, 1889, 2821, 3094, 376, 1570, 1000, 1459, 3042, 1205, 2651, 4151, 1077, 4081, 4758, 2336, 70, 3891, 2695, 4193, 2389, 3482, 1868, 1690, 462, 3394, 4965, 4653, 4515, 1495, 3356, 458, 370, 4883, 4657, 1233, 4223, 2759, 860, 1167, 3649, 4452, 4404, 618, 194, 2572, 2013, 3244, 2500, 2020, 1439, 1303, 2306, 3295, 2558, 3368, 4960, 1877, 256, 4287, 3556, 2911, 3836, 1217, 3827, 4761, 3460, 3429, 516, 3646, 2441, 3509, 199, 4583, 1730, 4800, 1251, 2827, 2509, 158, 808, 4372, 2287, 1500, 3523, 3785, 185, 4645, 2080, 4341, 4449, 4434, 3211, 3737, 4487, 1351, 1735, 3840, 4786, 560, 4361, 702, 2284, 1290, 4102, 4880, 1108, 4002, 1933, 159, 4776, 3832, 2101, 4523, 1024, 4227, 1969, 4569, 3692, 4197, 3952, 3010, 3499, 213] 
# print(' '.join(str(x) for x in numbers))
print(numbers, "\n")
os.system("make fclean && make && ./push_swap " + ' '.join(str(x)
          for x in numbers) + " | wc -l")