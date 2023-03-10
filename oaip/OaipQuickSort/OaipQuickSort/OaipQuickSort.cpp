#include<iostream>
#include<fstream>
#include<stdio.h>
#include<map>
class Teams {
public:
	class InformationAboutTeams {
		public:
			char* Names;
			int Number, Age, Height, Weight;
			char* TeamName;
			char *Country;
	};
	InformationAboutTeams* AddToFile();
	InformationAboutTeams* ShowTheFile();
	InformationAboutTeams* ChangeTheFile();
	int LinearSearch(int);
	void DirectlySort();
	void Quick_Sort(int,int);
	int BinarySearch(int);
	bool CheckFileSize(std::ifstream&);
	bool LenthOfName(std::ifstream&,InformationAboutTeams*);
	void MyTeam_Out();
	void QuickSort();
	void Task();
private:
	InformationAboutTeams* MyTeams;
	int SizeOfTeam;
	bool CheckSort = false;
};
int main() {
	int Choice = 0;
	bool Again = true;
	int key = 0;
	Teams Competition{};
	while (Again == true) {
		std::cout << "1.Correct file.\n2.LinearSearch.\n3.DirectlySort.\n4.QuickSort.\n5.BinarySearch.\n6.Task\n7.Exit" << std::endl;
		std::cin >> Choice;
		switch (Choice)
		{
		case 1:
			std::cout << std::endl;
			std::cout << "1.Add to file.\n2.Show the file.\n3.Change the file." << std::endl;
			std::cin >> Choice;
			std::cin.ignore(INT_MAX, '\n');
			switch (Choice)
			{
			case 1:
				Competition.AddToFile();
				break;
			case 2:
				Competition.MyTeam_Out();
				break;
			case 3:
				Competition.ChangeTheFile();
				break;
			}
			break;
		case 2:
			{std::cout << "Enter an element, which need to find: ";
			std::cin >> key;
			int index = Competition.BinarySearch(key);
			if (index == INT_MIN) {
				std::cout << "Such element not exist!" << std::endl;
				break;
			}
			std::cout << "The index of your element is: " << index << std::endl; }
			break;
		case 3:
			Competition.DirectlySort();
			break;
		case 4:
			Competition.QuickSort(); 
			break;
		case 5:
			{std::cout << "Enter an element in order to find it: ";
			std::cin >> key;
			int index = Competition.BinarySearch(key);
			if (index == INT_MIN) {
				std::cout << "Such element not exist!" << std::endl;
				break;
			}
			std::cout << "The index of your element is: " << index << std::endl; }
			break;
		case 6:
			Competition.Task();
			break;
		case 7:
			Again = false;
			break;
		}
	}
	return 0;
}
Teams::InformationAboutTeams* Teams::AddToFile() {
	char BufferName[100]{},BufferTeameName[100]{},BufferCountry[100]{};
	int counter = 0;
	SizeOfTeam++;
	InformationAboutTeams* BufferArray = new InformationAboutTeams[SizeOfTeam];
	for (int i = 0; i < SizeOfTeam-1; i++) {
		BufferArray[i] = MyTeams[i];
	}
	std::cout << "Enter a athlete's name:" << std::endl;
	gets_s(BufferName);
	for (int i = 0; i < 100; i++) {
		if (BufferName[i] == '\0') {
			break;
		}
		counter++;
	}
	BufferArray[SizeOfTeam-1].Names = new char[counter];
	for (int i = 0; i < counter;i++) {
		BufferArray[SizeOfTeam-1].Names[i] = BufferName[i];
	}
	BufferArray[SizeOfTeam-1].Names[counter] = '\0';
	std::cout << "Number of players:" << std::endl;
	std::cin >> BufferArray[SizeOfTeam - 1].Number;
	std::cout << "Age of players:" << std::endl;
	std::cin >> BufferArray[SizeOfTeam - 1].Age;
	std::cout << "Height of players:" << std::endl;
	std::cin >> BufferArray[SizeOfTeam - 1].Height;
	std::cout << "Weight of players:" << std::endl;
	std::cin >> BufferArray[SizeOfTeam - 1].Weight;
	std::cout << "Country of players:" << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	gets_s(BufferCountry);
	counter = 0;
	for (int i = 0; i < 100; i++) {
		if (BufferCountry[i] == '\0') {
			break;
		}
		counter++;
	}
	BufferArray[SizeOfTeam - 1].Country = new char[counter];
	for (int i = 0; i < counter; i++) {
		BufferArray[SizeOfTeam - 1].Country[i] = BufferCountry[i];
	}
	BufferArray[SizeOfTeam - 1].Country[counter] = '\0';
	std::cout << "Team of players:" << std::endl;
	gets_s(BufferTeameName);
	counter = 0;
	for (int i = 0; i < 100; i++) {
		if (BufferTeameName[i] == '\0') {
			break;
		}
		counter++;
	}
	BufferArray[SizeOfTeam - 1].TeamName= new char[counter];
	for (int i = 0; i < counter; i++) {
		BufferArray[SizeOfTeam - 1].TeamName[i] = BufferTeameName[i];
	}
	BufferArray[SizeOfTeam - 1].TeamName[counter] = '\0';
	MyTeams = new InformationAboutTeams[SizeOfTeam];
	MyTeams = BufferArray;
	std::ofstream file;
	file.open("Myteam.txt",std::fstream::app);
	file << MyTeams[SizeOfTeam-1].Names<<"\t";
	file << MyTeams[SizeOfTeam - 1].Number << "\t";
	file << MyTeams[SizeOfTeam - 1].Age << "\t";
	file << MyTeams[SizeOfTeam - 1].Height << "\t";
	file << MyTeams[SizeOfTeam - 1].Weight << "\t";
	file << MyTeams[SizeOfTeam - 1].Country << "\t";
	file << MyTeams[SizeOfTeam - 1].TeamName << "\n";
	file.close();
	delete[]BufferArray;
	return MyTeams;
}
Teams::InformationAboutTeams* Teams::ShowTheFile() {
	std::cout << std::endl;
	SizeOfTeam = 0;
	int Lenth = 0;
	char Buffer[100]{};
	bool Again = false;
	InformationAboutTeams* BufferArray = new InformationAboutTeams[1];
	std::ifstream FileOut;
	FileOut.open("Myteam.txt");
	
	while (Again==false) {
		Lenth = 0;
		for (int i = 0; i < SizeOfTeam; i++) {
			BufferArray[i] = MyTeams[i];
		}
		if (LenthOfName(FileOut, BufferArray) == false) {
			Again == true;
			break;
		};
		FileOut >> BufferArray[SizeOfTeam].Number;
		FileOut >> BufferArray[SizeOfTeam].Age;
		FileOut >> BufferArray[SizeOfTeam].Height;
		FileOut >> BufferArray[SizeOfTeam].Weight;
		FileOut >> Buffer;
		for (int i = 0; i < 100; i++) {
			if (Buffer[i] == '\0') {
				break;
			}
			Lenth++;
		}
		BufferArray[SizeOfTeam].Country=new char[Lenth];
		for (int i = 0; i < Lenth; i++) {
			BufferArray[SizeOfTeam].Country[i]=Buffer[i];
		}
		BufferArray[SizeOfTeam].Country[Lenth] = '\0';
		Lenth = 0;
		FileOut >> Buffer;
		for (int i = 0; i < 100; i++) {
			if (Buffer[i] == '\0') {
				break;
			}
			Lenth++;
		}
		BufferArray[SizeOfTeam].TeamName = new char[Lenth+1];
		for (int i = 0; i < Lenth; i++) {
			BufferArray[SizeOfTeam].TeamName[i] = Buffer[i];
		}
		BufferArray[SizeOfTeam].TeamName[Lenth] = '\n';
		BufferArray[SizeOfTeam].TeamName[Lenth+1] = '\0';
		MyTeams = new InformationAboutTeams[SizeOfTeam +1];
		MyTeams = BufferArray;
		SizeOfTeam++;
		BufferArray = new InformationAboutTeams[SizeOfTeam + 1];
	}
	return 0;
}
void Teams::MyTeam_Out() {
	ShowTheFile();
	for (int i = 0; i < SizeOfTeam; i++) {
		std::cout << i << ":" <<"Players name: " << MyTeams[i].Names << "; ";
		std::cout << "Number: " << MyTeams[i].Number << "; ";
		std::cout <<"Age: " << MyTeams[i].Age << "; ";
		std::cout <<"Height: " << MyTeams[i].Height << "; ";
		std::cout << "Weight: " << MyTeams[i].Weight << "; ";
		std::cout << "Country: " << MyTeams[i].Country << "; ";
		std::cout << "TeamName: " << MyTeams[i].TeamName <<std::endl;
	}
}
void Teams::QuickSort()
{
	ShowTheFile();
	Quick_Sort(0, SizeOfTeam-1);
}
Teams::InformationAboutTeams* Teams::ChangeTheFile()
{
	std::ifstream checkfile;
	checkfile.open("Myteam.txt");
	if (CheckFileSize(checkfile) == false) {
		std::cout << "File is empty!"<<std::endl;
		return MyTeams;
	}
	checkfile.close();
	char BufferName[100]{}, BufferTeameName[100]{}, BufferCountry[100]{};
	int counter = 0;
	int Choice = 0;
	std::cout << "Choose a line to change:" << std::endl;;
	std::cin >> Choice;
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Enter a athlete's name:" << std::endl;
	gets_s(BufferName);
	for (int i = 0; i < 100; i++) {
		if (BufferName[i] == '\0') {
			break;
		}
		counter++;
	}
	MyTeams[Choice].Names = new char[counter];
	for (int i = 0; i < counter; i++) {
		MyTeams[Choice].Names[i] = BufferName[i];
	}
	MyTeams[Choice].Names[counter] = '\0';
	std::cout << "Number of players:" << std::endl;
	std::cin >> MyTeams[Choice].Number;
	std::cout << "Age of players:" << std::endl;
	std::cin >> MyTeams[Choice].Age;
	std::cout << "Height of players:" << std::endl;
	std::cin >> MyTeams[Choice].Height;
	std::cout << "Weight of players:" << std::endl;
	std::cin >> MyTeams[Choice].Weight;
	std::cout << "Country of players:" << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	gets_s(BufferCountry);
	counter = 0;
	for (int i = 0; i < 100; i++) {
		if (BufferCountry[i] == '\0') {
			break;
		}
		counter++;
	}
	MyTeams[Choice].Country = new char[counter];
	for (int i = 0; i < counter; i++) {
		MyTeams[Choice].Country[i] = BufferCountry[i];
	}
	MyTeams[Choice].Country[counter] = '\0';
	std::cout << "Team of players:" << std::endl;
	gets_s(BufferTeameName);
	counter = 0;
	for (int i = 0; i < 100; i++) {
		if (BufferTeameName[i] == '\0') {
			break;
		}
		counter++;
	}
	MyTeams[Choice].TeamName = new char[counter];
	for (int i = 0; i < counter; i++) {
		MyTeams[Choice].TeamName[i] = BufferTeameName[i];
	}
	std::ofstream file;
	file.open("Myteam.txt");
	MyTeams[Choice].TeamName[counter] = '\0';
	for (int i = 0; i < SizeOfTeam; i++) {
		file << MyTeams[i].Names << "\t";
		file << MyTeams[i].Number << "\t";
		file << MyTeams[i].Age << "\t";
		file << MyTeams[i].Height << "\t";
		file << MyTeams[i].Weight << "\t";
		file << MyTeams[i].Country << "\t";
		file << MyTeams[i].TeamName << "\n";
	}
	file.close();
	return MyTeams;
}
int Teams::LinearSearch(int key)
{	
	ShowTheFile();
	if (SizeOfTeam == 0) {
		std::cout << "The team is empty!" << std::endl;
		return -1;
	}
	for (int i = 0; i < SizeOfTeam; i++) {
		if (MyTeams[i].Age == key) {
			return i;
		}
	}
	return INT_MIN;
}
void Teams::DirectlySort()
{
	int min = 0;
	InformationAboutTeams buffer{};
	ShowTheFile();
	std::ofstream file;
	file.open("Myteam.txt");
	for (int i = 0; i < SizeOfTeam; i++) {
		min = i;
		for (int j = i+1; j < SizeOfTeam; j++) {
			if (MyTeams[j].Age < MyTeams[min].Age) {
				buffer = MyTeams[j];
				MyTeams[j] = MyTeams[min];
				MyTeams[min] = buffer;
			}
		}
	}
	for (int i = 0; i < SizeOfTeam; i++) {
		file << MyTeams[i].Names << "\t";
		file << MyTeams[i].Number << "\t";
		file << MyTeams[i].Age << "\t";
		file << MyTeams[i].Height << "\t";
		file << MyTeams[i].Weight << "\t";
		file << MyTeams[i].Country << "\t";
		file << MyTeams[i].TeamName << "\n";
	}
	file.close();
}
void Teams::Quick_Sort(int Start,int Finish)
{
	InformationAboutTeams buffer{};
	int middle = MyTeams[(Start + Finish) / 2].Age;
	int left = Start, right = Finish;

	do {
		while (MyTeams[left].Age < middle) left++;
		while (MyTeams[right].Age > middle) right--;

		if (left <= right) {
			buffer = MyTeams[right];
			MyTeams[right] = MyTeams[left];
			MyTeams[left] = buffer;
			left++;
			right--;
		}
	} while (left <= right);

	if (Start<right) {
		Quick_Sort(Start,right);
	}
	if (Finish > left) {
		Quick_Sort(left, Finish);
	}
	std::ofstream file;
	file.open("Myteam.txt");
	for (int i = 0; i < SizeOfTeam; i++) {
		file << MyTeams[i].Names << "\t";
		file << MyTeams[i].Number << "\t";
		file << MyTeams[i].Age << "\t";
		file << MyTeams[i].Height << "\t";
		file << MyTeams[i].Weight << "\t";
		file << MyTeams[i].Country << "\t";
		file << MyTeams[i].TeamName << "\n";
	}
	file.close();
}
int Teams::BinarySearch(int key)
{	
	ShowTheFile();
	if (CheckSort == false) {
		CheckSort = true;
		QuickSort();
	}
	int begin = 0, end = SizeOfTeam;
	do {

		int middle = (begin + end) / 2;
		if (key == MyTeams[middle].Age) {
			return middle;
		}else if (key < MyTeams[middle].Age) {
			end = middle - 1;
		}
		else if(key>MyTeams[middle].Age) {
			begin = middle + 1;
		}
		if (begin > end) {
			break;
		}
	} while (key);
	return INT_MIN;
}
bool Teams::CheckFileSize(std::ifstream& file1)
{
	file1.seekg(0, std::ios::end);
	int size = file1.tellg();
	if (size == -1) {
		return false;
	}
	return true;
}
bool Teams::LenthOfName(std::ifstream& file,InformationAboutTeams* BufferArray)
{
	int length = 0;
	int counter = 0;
	char BufferName1[100]{},BufferName2[100]{};
	file >> BufferName1;
	if (!(file >> BufferName2)) {
		return false;
	}
	for (int i = 0; i < 100; i++) {
		if (BufferName1[i] == '\0') {
			break;
		}
		counter++;
	}
	length = counter;
	for (int i = 0; i < 100; i++) {
		if (BufferName2[i] == '\0') {
			break;
		}
		counter++;
	}
	BufferArray[SizeOfTeam].Names = new char[counter];
	for (int i = 0; i < length; i++) {
		BufferArray[SizeOfTeam].Names[i] = BufferName1[i];
	}
	BufferArray[SizeOfTeam].Names[length] = ' ';
	for (int i = length+1; i < counter+1; i++) {
		BufferArray[SizeOfTeam].Names[i] = BufferName2[i-(length+1)];
	}
	BufferArray[SizeOfTeam].Names[counter+1] = '\0';
	return true;
}
void Teams::Task() {
	ShowTheFile();
	std::map <std::string, std::pair<int,int>> TeamsAge;
	std::pair<int, int> buffer;

	for (int i = 0; i < SizeOfTeam; i++) {

		if (TeamsAge.find(MyTeams[i].TeamName) == TeamsAge.end()) {
			buffer.first = MyTeams[i].Age;
			buffer.second = 1;
			TeamsAge.emplace(MyTeams[i].TeamName, buffer);
		}
		else
		{
			buffer.second= TeamsAge[MyTeams[i].TeamName].second + 1;
			buffer.first = TeamsAge[MyTeams[i].TeamName].first+ MyTeams[i].Age;
			TeamsAge.erase(MyTeams[i].TeamName);
			TeamsAge.emplace(MyTeams[i].TeamName, buffer);
		}

	}


	std::map<std::string, std::pair<int, int>>::iterator it;

	std::map < std::string, std::pair<int, int> >::iterator min = TeamsAge.begin();

	for (it = TeamsAge.begin(); it != TeamsAge.end(); it++) {
		it->second.first = it->second.first / it->second.second;
		if (it->second < min->second) {
			min = it;
		}
	}

	std::string TeamName = min->first;

	for (int i = 0; i < SizeOfTeam; i++) {
		if (MyTeams[i].TeamName == TeamName) {
			std::cout << "Players name: " << MyTeams[i].Names << "; ";
			std::cout << "Number: " << MyTeams[i].Number << "; ";
			std::cout << "Age: " << MyTeams[i].Age << "; ";
			std::cout << "Height: " << MyTeams[i].Height << "; ";
			std::cout << "Weight: " << MyTeams[i].Weight << "; ";
			std::cout << "Country: " << MyTeams[i].Country << "; ";
			std::cout << "TeamName: " << MyTeams[i].TeamName << std::endl;
		}
	}
}

