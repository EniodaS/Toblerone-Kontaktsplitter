namespace Toblerone_Tests
{
    [TestFixture]
    public class ParserTests
    {
        private Parser parser;  // Replace 'YourNamespace' with the actual namespace of your C++/CLI project

        [SetUp]
        public void Setup()
        {
            // Assuming DataClass can be constructed with default values suitable for testing
            var dataClass = new DataClass();
            parser = new Parser(dataClass);
        }

        [Test]
        public void TestParseEingabe_SimpleCase()
        {
            // Arrange
            string input = "Herr Dr. Max Mustermann";

            // Act
            parser.parseEingabe(input);


            // Assert
            Assert.IsTrue("Dr. " == parser.getTitel1());
            //Assert.AreEqual("Herr ", parser.getAnrede(), "Anrede should be 'Herr '");
            //Assert.AreEqual("Dr. ", parser.getTitel1(), "First title should be 'Dr. '");
            //Assert.AreEqual("", parser.getTitel2(), "Second title should be empty");
            //Assert.AreEqual("Max ", parser.getVorname(), "Vorname should be 'Max '");
            //Assert.AreEqual("Mustermann ", parser.getNachname(), "Nachname should be 'Mustermann '");
            //Assert.AreEqual("Männlich", parser.getGeschlecht(), "Geschlecht should be 'Männlich'");
            //Assert.AreEqual("Sehr geehrter ", parser.getBriefAnrede(), "BriefAnrede should be 'Sehr geehrter '");
        }
    }
}