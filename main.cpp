#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string reference_filepath, current_filepath;

    cout << "Hello!\nPlease drag and drop the plot spectrum results for the reference audio, then for the current audio, then press Enter.\n";

    getline(cin, reference_filepath);
    getline(cin, current_filepath);

    ifstream ref_in(reference_filepath);
    ifstream cur_in(current_filepath);

    string junk;
    getline(ref_in, junk);
	getline(cur_in, junk);

	ofstream out("Correct current.xml");

	out << "<equalizationeffect>\n	<curve name=\"Correct current\">\n";

	long double ref_point, cur_point;
	while (ref_in >> ref_point && cur_in >> cur_point) {
		long double ref_level, cur_level;
		ref_in >> ref_level, cur_in >> cur_level;

		out << "		<point f=\"" << ref_point << "\" d=\"" << ref_level - cur_level << "\"/>\n";
	}
	out << "	</curve>\n</equalizationeffect>";

	cout << "File saved as Correct current.xml in running directory.";
	getchar();
}
