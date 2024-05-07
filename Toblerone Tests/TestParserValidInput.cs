namespace Toblerone_Tests
{
    [TestFixture]
    public class TestParserValidInput
    {
        Parser parser;  // Replace 'YourNamespace' with the actual namespace of your C++/CLI project

        [SetUp]
        public void Setup()
        {
            // Assuming DataClass can be constructed with default values suitable for testing
            var dataClass = new DataClass();
            parser = new Parser(dataClass);
        }

        [Test]
        public void TestParseValidInput_Testcase01()
        {
            // descr

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
            // descr

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
            // descr

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

        public void compareKontakte(Kontakt kontakt1,  Kontakt kontakt2)
        {
            Assert.That(kontakt1.getAnrede(), Is.EqualTo(kontakt2.getAnrede()), "Unterschiedliche Anreden! " + kontakt1.getAnrede() + ", " + kontakt2.getAnrede());
            Assert.That(kontakt1.getGeschlecht(), Is.EqualTo(kontakt2.getGeschlecht()), "Unterschiedliche Geschlechter! " + kontakt1.getGeschlecht() + ", " + kontakt2.getGeschlecht());
            Assert.That(kontakt1.getTitel1(), Is.EqualTo(kontakt2.getTitel1()), "Unterschiedliche erste Titel! " + kontakt1.getTitel1() + ", " + kontakt2.getTitel1());
            Assert.That(kontakt1.getTitel2(), Is.EqualTo(kontakt2.getTitel2()), "Unterschiedliche zweite Titel! " + kontakt1.getTitel2() + ", " + kontakt2.getTitel2());
            Assert.That(kontakt1.getVorname1(), Is.EqualTo(kontakt2.getVorname1()), "Unterschiedliche erste Vornamen! " + kontakt1.getVorname1() + ", " + kontakt2.getVorname1());
            Assert.That(kontakt1.getVorname2(), Is.EqualTo(kontakt2.getVorname2()), "Unterschiedliche zweite Vornamen! " + kontakt1.getVorname2() + ", " + kontakt2.getVorname2());
            Assert.That(kontakt1.getNachname1(), Is.EqualTo(kontakt2.getNachname1()), "Unterschiedliche erste Nachnamen! " + kontakt1.getNachname1() + ", " + kontakt2.getNachname1());
            Assert.That(kontakt1.getNachname2(), Is.EqualTo(kontakt2.getNachname2()), "Unterschiedliche zweite Nachnamen! " + kontakt1.getNachname2() + ", " + kontakt2.getNachname2());
        }
    }
}