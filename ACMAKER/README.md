The sadists who design problems for ACM programming contests often like to include the abbre- viation “ACM” somewhere in their problem descriptions. Thus, in years past, the World Finals has had problems involving “Apartment Construction Management,” the “Atheneum of Culture and Movies,” the “Association of Cover Manufacturers,” “ACM Airlines,” the “Association for Computa- tional Marinelife,” and even an insect named “Amelia Cheese Mite.” However, the number of word combinations beginning with A, C, and M that make sense is finite and the problem writers are starting to run out of ideas (it’s hard to think of problems about “Antidisestablishmentarianistic Chthonian Metalinguistics”). Fortunately, modern culture allows more flexibility in designing abbreviations — consider, for example:

GDB — Gnu DeBugger
LINUX — either “LINus’s UniX” or “LINUs’s miniX” or “Linux Is Not UniX”
SNOBOL — StriNg Oriented symBOlic Language
SPITBOL — SPeedy ImplemenTation of snoBOL
The rules used in these examples seem to be:

Insignificant words (such as “of”, “a”, “the”, etc.) are ignored.
The letters of the abbreviation must appear, in the correct order, as an ordered sublist of the letters in the significant words of the phrase to be abbreviated.
At least one letter of the abbreviation must come from every significant word (multiple occurrences of a letter are, of course, treated as distinct).
Of course these rules are often broken in real life. For instance, RADAR is an abbreviation for “RAdio Detecting And Ranging”. Under our rules (assuming that “and” is an insignificant word), this would not be a valid abbreviation (however, RADR or RADRAN or DODGING would be valid). You have been asked to take a list of insignificant words and a list of abbreviations and phrases and to determine in how many ways each abbreviation can be formed from the corresponding phrase according to the rules above.

Instructions:
1.To build run command
    make
2.To run testcases run command in current directory
    ./runCases.sh

3.Maintain Testcases

List of all the failed testcases is entered into TestResult/failedCases.
Analyze the failiures by looking at TEST files in the respective directory. Regold the testcases by running the following command.

./reGold.sh TestResult/failedCases

