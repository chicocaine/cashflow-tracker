#ifndef CURRENCIES_H
#define CURRENCIES_H

typedef enum {
  CURRENCY_UNKNOWN = 0,
  CURRENCY_AED, // United Arab Emirates Dirham
  CURRENCY_AFN, // Afghan Afghani
  CURRENCY_ALL, // Albanian Lek
  CURRENCY_AMD, // Armenian Dram
  CURRENCY_ANG, // Netherlands Antillean Guilder
  CURRENCY_AOA, // Angolan Kwanza
  CURRENCY_ARS, // Argentine Peso
  CURRENCY_AUD, // Australian Dollar
  CURRENCY_AWG, // Aruban Florin
  CURRENCY_AZN, // Azerbaijani Manat
  CURRENCY_BAM, // Bosnia and Herzegovina Convertible Mark
  CURRENCY_BBD, // Barbadian Dollar
  CURRENCY_BDT, // Bangladeshi Taka
  CURRENCY_BGN, // Bulgarian Lev
  CURRENCY_BHD, // Bahraini Dinar
  CURRENCY_BIF, // Burundian Franc
  CURRENCY_BMD, // Bermudian Dollar
  CURRENCY_BND, // Brunei Dollar
  CURRENCY_BOB, // Bolivian Boliviano
  CURRENCY_BRL, // Brazilian Real
  CURRENCY_BSD, // Bahamian Dollar
  CURRENCY_BTN, // Bhutanese Ngultrum
  CURRENCY_BWP, // Botswanan Pula
  CURRENCY_BYN, // Belarusian Ruble
  CURRENCY_BZD, // Belize Dollar
  CURRENCY_CAD, // Canadian Dollar
  CURRENCY_CDF, // Congolese Franc
  CURRENCY_CHF, // Swiss Franc
  CURRENCY_CLP, // Chilean Peso
  CURRENCY_CNY, // Chinese Yuan
  CURRENCY_COP, // Colombian Peso
  CURRENCY_CRC, // Costa Rican Colón
  CURRENCY_CUC, // Cuban Convertible Peso
  CURRENCY_CUP, // Cuban Peso
  CURRENCY_CVE, // Cape Verdean Escudo
  CURRENCY_CZK, // Czech Koruna
  CURRENCY_DJF, // Djiboutian Franc
  CURRENCY_DKK, // Danish Krone
  CURRENCY_DOP, // Dominican Peso
  CURRENCY_DZD, // Algerian Dinar
  CURRENCY_EGP, // Egyptian Pound
  CURRENCY_ERN, // Eritrean Nakfa
  CURRENCY_ETB, // Ethiopian Birr
  CURRENCY_EUR, // Euro
  CURRENCY_FJD, // Fijian Dollar
  CURRENCY_FKP, // Falkland Islands Pound
  CURRENCY_GBP, // British Pound Sterling
  CURRENCY_GEL, // Georgian Lari
  CURRENCY_GHS, // Ghanaian Cedi
  CURRENCY_GIP, // Gibraltar Pound
  CURRENCY_GMD, // Gambian Dalasi
  CURRENCY_GNF, // Guinean Franc
  CURRENCY_GTQ, // Guatemalan Quetzal
  CURRENCY_GYD, // Guyanaese Dollar
  CURRENCY_HKD, // Hong Kong Dollar
  CURRENCY_HNL, // Honduran Lempira
  CURRENCY_HRK, // Croatian Kuna
  CURRENCY_HTG, // Haitian Gourde
  CURRENCY_HUF, // Hungarian Forint
  CURRENCY_IDR, // Indonesian Rupiah
  CURRENCY_ILS, // Israeli New Shekel
  CURRENCY_INR, // Indian Rupee
  CURRENCY_IQD, // Iraqi Dinar
  CURRENCY_IRR, // Iranian Rial
  CURRENCY_ISK, // Icelandic Króna
  CURRENCY_JMD, // Jamaican Dollar
  CURRENCY_JOD, // Jordanian Dinar
  CURRENCY_JPY, // Japanese Yen
  CURRENCY_KES, // Kenyan Shilling
  CURRENCY_KGS, // Kyrgyzstani Som
  CURRENCY_KHR, // Cambodian Riel
  CURRENCY_KMF, // Comorian Franc
  CURRENCY_KPW, // North Korean Won
  CURRENCY_KRW, // South Korean Won
  CURRENCY_KWD, // Kuwaiti Dinar
  CURRENCY_KYD, // Cayman Islands Dollar
  CURRENCY_KZT, // Kazakhstani Tenge
  CURRENCY_LAK, // Laotian Kip
  CURRENCY_LBP, // Lebanese Pound
  CURRENCY_LKR, // Sri Lankan Rupee
  CURRENCY_LRD, // Liberian Dollar
  CURRENCY_LSL, // Lesotho Loti
  CURRENCY_LYD, // Libyan Dinar
  CURRENCY_MAD, // Moroccan Dirham
  CURRENCY_MDL, // Moldovan Leu
  CURRENCY_MGA, // Malagasy Ariary
  CURRENCY_MKD, // Macedonian Denar
  CURRENCY_MMK, // Myanmar Kyat
  CURRENCY_MNT, // Mongolian Tugrik
  CURRENCY_MOP, // Macanese Pataca
  CURRENCY_MRU, // Mauritanian Ouguiya
  CURRENCY_MUR, // Mauritian Rupee
  CURRENCY_MVR, // Maldivian Rufiyaa
  CURRENCY_MWK, // Malawian Kwacha
  CURRENCY_MXN, // Mexican Peso
  CURRENCY_MYR, // Malaysian Ringgit
  CURRENCY_MZN, // Mozambican Metical
  CURRENCY_NAD, // Namibian Dollar
  CURRENCY_NGN, // Nigerian Naira
  CURRENCY_NIO, // Nicaraguan Córdoba
  CURRENCY_NOK, // Norwegian Krone
  CURRENCY_NPR, // Nepalese Rupee
  CURRENCY_NZD, // New Zealand Dollar
  CURRENCY_OMR, // Omani Rial
  CURRENCY_PAB, // Panamanian Balboa
  CURRENCY_PEN, // Peruvian Sol
  CURRENCY_PGK, // Papua New Guinean Kina
  CURRENCY_PHP, // Philippine Peso
  CURRENCY_PKR, // Pakistani Rupee
  CURRENCY_PLN, // Polish Zloty
  CURRENCY_PYG, // Paraguayan Guarani
  CURRENCY_QAR, // Qatari Rial
  CURRENCY_RON, // Romanian Leu
  CURRENCY_RSD, // Serbian Dinar
  CURRENCY_RUB, // Russian Ruble
  CURRENCY_RWF, // Rwandan Franc
  CURRENCY_SAR, // Saudi Riyal
  CURRENCY_SBD, // Solomon Islands Dollar
  CURRENCY_SCR, // Seychellois Rupee
  CURRENCY_SDG, // Sudanese Pound
  CURRENCY_SEK, // Swedish Krona
  CURRENCY_SGD, // Singapore Dollar
  CURRENCY_SHP, // Saint Helena Pound
  CURRENCY_SLL, // Sierra Leonean Leone
  #define CURRENCY_SLE CURRENCY_SLL // Alternative code for New Leone
  CURRENCY_SOS, // Somali Shilling
  CURRENCY_SRD, // Surinamese Dollar
  CURRENCY_SSP, // South Sudanese Pound
  CURRENCY_STN, // São Tomé and Príncipe Dobra
  CURRENCY_SVC, // Salvadoran Colón
  CURRENCY_SYP, // Syrian Pound
  CURRENCY_SZL, // Swazi Lilangeni
  CURRENCY_THB, // Thai Baht
  CURRENCY_TJS, // Tajikistani Somoni
  CURRENCY_TMT, // Turkmenistani Manat
  CURRENCY_TND, // Tunisian Dinar
  CURRENCY_TOP, // Tongan Paʻanga
  CURRENCY_TRY, // Turkish Lira
  CURRENCY_TTD, // Trinidad and Tobago Dollar
  CURRENCY_TWD, // New Taiwan Dollar
  CURRENCY_TZS, // Tanzanian Shilling
  CURRENCY_UAH, // Ukrainian Hryvnia
  CURRENCY_UGX, // Ugandan Shilling
  CURRENCY_USD, // United States Dollar
  CURRENCY_UYU, // Uruguayan Peso
  CURRENCY_UZS, // Uzbekistani Som
  CURRENCY_VES, // Venezuelan Bolívar Soberano
  CURRENCY_VND, // Vietnamese Dong
  CURRENCY_VUV, // Vanuatu Vatu
  CURRENCY_WST, // Samoan Tala
  CURRENCY_XAF, // Central African CFA Franc
  CURRENCY_XCD, // East Caribbean Dollar
  CURRENCY_XOF, // West African CFA Franc
  CURRENCY_XPF, // CFP Franc
  CURRENCY_YER, // Yemeni Rial
  CURRENCY_ZAR, // South African Rand
  CURRENCY_ZMW, // Zambian Kwacha
  CURRENCY_ZWL, // Zimbabwean Dollar
  CURRENCY_COUNT
} Currency;

#endif // CURRENCIES_H
