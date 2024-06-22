from lab2.database import DataBase


if __name__ == "__main__":
    db = DataBase()

    db.add_country("UA", "Ukraine")
    db.add_country("US", "United States")
    db.add_country("UK", "United Kingdom")
    db.add_country("FR", "France")
    db.add_country("DE", "Germany")
    db.add_country("IT", "Italy")
    db.add_country("ES", "Spain")
    db.add_country("CA", "Canada")
    db.add_country("AU", "Australia")
    db.add_country("JP", "Japan")
    db.add_country("CN", "China")
    db.add_country("BR", "Brazil")
    db.add_country("IN", "India")
    db.add_country("RU", "Russia")

    db.add_city("KYIV", "UA", "Kyiv", 2804000, True)
    db.add_city("LVIV", "UA", "Lviv", 3792621, False)
    db.add_city("ODESA", "UA", "Odesa", 8175133, True)
    db.add_city("KHARKIV", "UA", "Kharkiv", 3792621, False)
    db.add_city("DNIPRO", "UA", "Dnipro", 8175133, True)
    db.add_city("VYSHNEVE", "UA", "Vyshneve", 3792621, False)
    db.add_city("IRPIN", "UA", "Irpin", 8175133, True)
    db.add_city("BROVARY", "UA", "Brovary", 3792621, False)
    db.add_city("BILA TSERKVA", "UA", "Bila Tserkva", 8175133, True)
    db.add_city("BOYARKA", "UA", "Boyarka", 3792621, False)
    db.add_city("BORYSPIL", "UA", "Boryspil", 8175133, True)
    db.add_city("VINNYTSIA", "UA", "Vinnytsia", 3792621, False)
    db.add_city("ZHYTOMYR", "UA", "Zhytomyr", 8175133, True)
    db.add_city("ZAPORIZHIA", "UA", "Zaporizhia", 3792621, False)
    db.add_city("IVANO-FRANKIVSK", "UA", "Ivano-Frankivsk", 8175133, True)
    db.add_city("KRYVYI RIH", "UA", "Kryvyi Rih", 3792621, False)
    db.add_city("LUTSK", "UA", "Lutsk", 8175133, True)
    db.add_city("MYKOLAIV", "UA", "Mykolaiv", 3792621, False)
    db.add_city("POLTAVA", "UA", "Poltava", 8175133, True)
    db.add_city("RIVNE", "UA", "Rivne", 3792621, False)
    db.add_city("SUMY", "UA", "Sumy", 8175133, True)
    db.add_city("TERNOPIL", "UA", "Ternopil", 3792621, False)
    db.add_city("UZHGOROD", "UA", "Uzhgorod", 8175133, True)
    db.add_city("KHMELNYTSKYI", "UA", "Khmelnytskyi", 3792621, False)
    db.add_city("CHERKASY", "UA", "Cherkasy", 8175133, True)
    db.add_city("CHERNIHIV", "UA", "Chernihiv", 3792621, False)
    db.add_city("CHERNIVTSI", "UA", "Chernivtsi", 8175133, True)

    db.add_city("DC", "US", "Washington", 3792621, False)
    db.add_city("NY", "US", "New York", 8175133, True)
    db.add_city("LA", "US", "Los Angeles", 3792621, False)

    db.add_city("LON", "UK", "London", 8175133, True)
    db.add_city("LIV", "UK", "Liverpool", 3792621, False)
    db.add_city("BIR", "UK", "Birmingham", 8175133, True)
    db.add_city("OXF", "UK", "Oxford", 3792621, False)

    db.add_city("PAR", "FR", "Paris", 3792621, False)
    db.add_city("MAR", "FR", "Marseille", 8175133, True)
    db.add_city("LYO", "FR", "Lyon", 3792621, False)
    db.add_city("TOU", "FR", "Toulouse", 8175133, True)
    db.add_city("NAN", "FR", "Nantes", 3792621, False)

    db.add_city("BER", "DE", "Berlin", 8175133, True)
    db.add_city("HAM", "DE", "Hamburg", 3792621, False)
    db.add_city("MUN", "DE", "Munich", 8175133, True)
    db.add_city("KOL", "DE", "Cologne", 3792621, False)

    db.add_city("CAS", "IT", "Casablanca", 8175133, True)
    db.add_city("ROM", "IT", "Rome", 3792621, False)

    db.add_city("MAD", "ES", "Madrid", 8175133, True)
    db.add_city("BAR", "ES", "Barcelona", 3792621, False)
    db.add_city("VAL", "ES", "Valencia", 8175133, True)

    db.add_city("OTT", "CA", "Ottawa", 3792621, False)
    db.add_city("TOR", "CA", "Toronto", 8175133, True)

    db.add_city("CAN", "AU", "Canberra", 8175133, True)
    db.add_city("SYD", "AU", "Sydney", 3792621, False)

    db.add_city("TOK", "JP", "Tokyo", 3792621, False)
    db.add_city("OSA", "JP", "Osaka", 8175133, True)

    db.add_city("BEI", "CN", "Beijing", 8175133, True)
    db.add_city("SHA", "CN", "Shanghai", 3792621, False)

    db.add_city("RIO", "BR", "Rio de Janeiro", 3792621, False)
    db.add_city("SAO", "BR", "Sao Paulo", 8175133, True)

    db.add_city("DEL", "IN", "Delhi", 8175133, True)
    db.add_city("MUM", "IN", "Mumbai", 3792621, False)

    db.add_city("MOS", "RU", "Moscow", 3792621, False)
    db.add_city("BEL", "RU", "Belgorod", 8175133, True)

    # Print all countries and cities
    print(db.find_country_by_code("US"))
    print(db.find_cities_by_country("UA"))
    print(db.countries())
    print(db.cities())
    print(db.cities("US"))

    # Update country and city
    db.update_country("RU", "Katsapstan")
    db.update_city("BEL", "RU", "Bilgorod", 817, False)

    # Delete country and city
    db.delete_city("MOS")
    db.delete_city("BEL")
    db.delete_country("RU")

    print(db.countries())
    print(db.cities())
    print(db.cities("RU"))
