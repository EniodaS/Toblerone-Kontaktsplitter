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
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
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
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
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
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
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
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
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
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
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
            string expectedAusgabe1 = "Sehr geehrter Herr Prof. Antonius";
            string expectedAusgabe2 = "Sehr geehrte*r Sylvie van der Vaart";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
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
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
        }

        [Test]
        public void TestParseValidInput_Testcase08()
        {
            // Sonderfälle Präfix
            // Arrange
            string input1 = "Von Anhalt";
            string input2 = "Bob de Kurz-Fink";
            string input3 = "Professor Heinrich Freiherr vom Wald";
            Kontakt expectedKontakt1 = new Kontakt("", "X", "", "", "", "", "Von Anhalt", "");
            Kontakt expectedKontakt2 = new Kontakt("", "X", "", "", "Bob", "", "de Kurz", "Fink");
            Kontakt expectedKontakt3 = new Kontakt("", "X", "Professor", "", "Heinrich", "", "Freiherr", "vom Wald");
            string expectedAusgabe1 = "Sehr geehrte*r Von Anhalt";
            string expectedAusgabe2 = "Sehr geehrte*r Bob de Kurz-Fink";
            string expectedAusgabe3 = "Sehr geehrte*r Professor Heinrich Freiherr vom Wald";

            // Act
            Kontakt kontakt1 = parser.parseEingabe(input1);
            Kontakt kontakt2 = parser.parseEingabe(input2);
            Kontakt kontakt3 = parser.parseEingabe(input3);
            string ausgabe1 = parser.generateAusgabe(kontakt1);
            string ausgabe2 = parser.generateAusgabe(kontakt2);
            string ausgabe3 = parser.generateAusgabe(kontakt3);

            // Assert
            compareKontakte(expectedKontakt1, kontakt1);
            compareKontakte(expectedKontakt2, kontakt2);
            compareKontakte(expectedKontakt3, kontakt3);
            Assert.That(ausgabe1 == expectedAusgabe1, Is.True);
            Assert.That(ausgabe2 == expectedAusgabe2, Is.True);
            Assert.That(ausgabe3 == expectedAusgabe3, Is.True);
        }

        public void compareKontakte(Kontakt expected, Kontakt actual)
        {
            Assert.That(expected.getAnrede(), Is.EqualTo(actual.getAnrede()), "Unterschiedliche Anreden! " + expected.getAnrede() + ", " + actual.getAnrede());
            Assert.That(expected.getGeschlecht(), Is.EqualTo(actual.getGeschlecht()), "Unterschiedliche Geschlechter! " + expected.getGeschlecht() + ", " + actual.getGeschlecht());
            Assert.That(expected.getTitel1(), Is.EqualTo(actual.getTitel1()), "Unterschiedliche erste Titel! " + expected.getTitel1() + ", " + actual.getTitel1());
            Assert.That(expected.getTitel2(), Is.EqualTo(actual.getTitel2()), "Unterschiedliche zweite Titel! " + expected.getTitel2() + ", " + actual.getTitel2());
            Assert.That(expected.getVorname1(), Is.EqualTo(actual.getVorname1()), "Unterschiedliche erste Vornamen! " + expected.getVorname1() + ", " + actual.getVorname1());
            Assert.That(expected.getVorname2(), Is.EqualTo(actual.getVorname2()), "Unterschiedliche zweite Vornamen! " + expected.getVorname2() + ", " + actual.getVorname2());
            Assert.That(expected.getNachname1(), Is.EqualTo(actual.getNachname1()), "Unterschiedliche erste Nachnamen! " + expected.getNachname1() + ", " + actual.getNachname1());
            Assert.That(expected.getNachname2(), Is.EqualTo(actual.getNachname2()), "Unterschiedliche zweite Nachnamen! " + expected.getNachname2() + ", " + actual.getNachname2());
        }
    }
}