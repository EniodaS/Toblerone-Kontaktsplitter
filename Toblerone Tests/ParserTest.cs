namespace Toblerone_Tests
{
    [TestFixture]
    public class TestParserValidInput
    {
        Parser parser; 

        [SetUp]
        public void Setup()
        {
            var dataClass = new DataClass();
            parser = new Parser(dataClass);
        }

        [Test]
        public void TestParseValidInput_Testcase01()
        {
            // Eingabe mit Kernangaben (Anrede Titel Vorname Nachname)
            // Arrange
            string input1 = "Herr Dr. Sandro Gutmensch";
            string input2 = "Frau Sandra Berger";
            Kontakt expectedKontakt1 = new Kontakt("Herr", "Männlich", "Dr.", "", "Sandro", "", "Gutmensch", "");
            Kontakt expectedKontakt2 = new Kontakt("Frau", "Weiblich", "", "", "Sandra", "", "Berger", "");
            string expectedAusgabe1 = "Sehr geehrter Herr Dr. Sandro Gutmensch";
            string expectedAusgabe2 = "Sehr geehrte Frau Sandra Berger";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Testcase02()
        {
            // Eingabe ohne Anrede
            // Arrange
            string input1 = "Prof. Robin Schulz";
            string input2 = "Charlie Chaplin";
            Kontakt expectedKontakt1 = new Kontakt("", "X", "Prof.", "", "Robin", "", "Schulz", "");
            Kontakt expectedKontakt2 = new Kontakt("", "X", "", "", "Charlie", "", "Chaplin", "");
            string expectedAusgabe1 = "Sehr geehrte*r Prof. Robin Schulz";
            string expectedAusgabe2 = "Sehr geehrte*r Charlie Chaplin";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Testcase03()
        {
            // Eingabe ohne Vorname
            // Arrange
            string input1 = "Baumann";
            string input2 = "Herr Professor Sadoine";
            Kontakt expectedKontakt1 = new Kontakt("", "X", "", "", "", "", "Baumann", "");
            Kontakt expectedKontakt2 = new Kontakt("Herr", "Männlich", "Professor", "", "", "", "Sadoine", "");
            string expectedAusgabe1 = "Sehr geehrte*r Baumann";
            string expectedAusgabe2 = "Sehr geehrter Herr Professor Sadoine";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Testcase04()
        {
            // Nachname, Vorname
            // Arrange
            string input1 = "Frau Professor Roland, Marianne";
            string input2 = "Dr. Russwurm, Winfried";
            Kontakt expectedKontakt1 = new Kontakt("Frau", "Weiblich", "Professor", "", "Marianne", "", "Roland", "");
            Kontakt expectedKontakt2 = new Kontakt("", "X", "Dr.", "", "Winfried", "", "Russwurm", "");
            string expectedAusgabe1 = "Sehr geehrte Frau Professor Marianne Roland";
            string expectedAusgabe2 = "Sehr geehrte*r Dr. Winfried Russwurm";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Testcase05()
        {
            // Namen mit Mehrfachtiteln
            // Arrange
            string input1 = "Herr Dipl. Ing. Max Müller";
            string input2 = "Prof. Dr. Bernd Brot";
            Kontakt expectedKontakt1 = new Kontakt("Herr", "Männlich", "Dipl.", "Ing.", "Max", "", "Müller", "");
            Kontakt expectedKontakt2 = new Kontakt("", "X", "Prof.", "Dr.", "Bernd", "", "Brot", "");
            string expectedAusgabe1 = "Sehr geehrter Herr Dipl. Ing. Max Müller";
            string expectedAusgabe2 = "Sehr geehrte*r Prof. Dr. Bernd Brot";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Testcase06()
        {
            // Namen mit Präfixen
            // Arrange
            string input1 = "Herr Professor Antonius van Hoof";
            string input2 = "Sylvie van der Vaart";
            Kontakt expectedKontakt1 = new Kontakt("Herr", "Männlich", "Professor", "", "Antonius", "", "van Hoof", "");
            Kontakt expectedKontakt2 = new Kontakt("", "X", "", "", "Sylvie", "", "van der Vaart", "");
            string expectedAusgabe1 = "Sehr geehrter Herr Professor Antonius van Hoof";
            string expectedAusgabe2 = "Sehr geehrte*r Sylvie van der Vaart";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Testcase07()
        {
            // Doppelnamen (doppelte Vor- und Nachnamen)
            // Arrange
            string input1 = "Frau Professor Doktor Ann-Kathrin Mayer-Schneider";
            string input2 = "Herr Bauer-Müller, Karl-Heinz";
            Kontakt expectedKontakt1 = new Kontakt("Frau", "Weiblich", "Professor", "Doktor", "Ann", "Kathrin", "Mayer", "Schneider");
            Kontakt expectedKontakt2 = new Kontakt("Herr", "Männlich", "", "", "Karl", "Heinz", "Bauer", "Müller");
            string expectedAusgabe1 = "Sehr geehrte Frau Professor Doktor Ann-Kathrin Mayer-Schneider";
            string expectedAusgabe2 = "Sehr geehrter Herr Karl-Heinz Bauer-Müller";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Edgecase01()
        {
            // Sonderfälle Mehrfachtitel
            // Arrange
            string input1 = "Frau Prof. Dr. rer. nat. Maria von Leuthäuser-Schnarrenberger";
            string input2 = "Herr Dr.-Ing. rer. nat. Dr. h.c. mult. von Zimmermann-Walter, Paul-Steffen";
            Kontakt expectedKontakt1 = new Kontakt("Frau", "Weiblich", "Prof.", "Dr. rer. nat.", "Maria", "", "von Leuthäuser", "Schnarrenberger");
            Kontakt expectedKontakt2 = new Kontakt("Herr", "Männlich", "Dr.-Ing. rer. nat.", "Dr. h.c. mult.", "Paul", "Steffen", "von Zimmermann", "Walter");
            string expectedAusgabe1 = "Sehr geehrte Frau Prof. Dr. rer. nat. Maria von Leuthäuser-Schnarrenberger";
            string expectedAusgabe2 = "Sehr geehrter Herr Dr.-Ing. rer. nat. Dr. h.c. mult. Paul-Steffen von Zimmermann-Walter";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        [Test]
        public void TestParseValidInput_Edgecase02()
        {
            // Sonderfälle Präfixe
            // Arrange
            string input1 = "Von Anhalt";
            string input2 = "Rheinland von Pfalz, Markus";
            Kontakt expectedKontakt1 = new Kontakt("", "X", "", "", "", "", "Von Anhalt", "");
            Kontakt expectedKontakt2 = new Kontakt("", "X", "", "", "Markus", "", "Rheinland", "von Pfalz");
            string expectedAusgabe1 = "Sehr geehrte*r Von Anhalt";
            string expectedAusgabe2 = "Sehr geehrte*r Markus Rheinland von Pfalz";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            //compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.AreEqual(expectedAusgabe1, ausgabe1);
            Assert.AreEqual(expectedAusgabe2, ausgabe2);
        }

        public void compareKontakte(Kontakt expected, Kontakt actual)
        {
            Assert.That(actual.getAnrede(), Is.EqualTo(expected.getAnrede()), "Unterschiedliche Anreden!");
            Assert.That(actual.getGeschlecht(), Is.EqualTo(expected.getGeschlecht()), "Unterschiedliche Geschlechter!");
            Assert.That(actual.getTitel1(), Is.EqualTo(expected.getTitel1()), "Unterschiedliche erste Titel!");
            Assert.That(actual.getTitel2(), Is.EqualTo(expected.getTitel2()), "Unterschiedliche zweite Titel!");
            Assert.That(actual.getVorname1(), Is.EqualTo(expected.getVorname1()), "Unterschiedliche erste Vornamen!");
            Assert.That(actual.getVorname2(), Is.EqualTo(expected.getVorname2()), "Unterschiedliche zweite Vornamen!");
            Assert.That(actual.getNachname1(), Is.EqualTo(expected.getNachname1()), "Unterschiedliche erste Nachnamen!");
            Assert.That(actual.getNachname2(), Is.EqualTo(expected.getNachname2()), "Unterschiedliche zweite Nachnamen!");
        }
    }
}