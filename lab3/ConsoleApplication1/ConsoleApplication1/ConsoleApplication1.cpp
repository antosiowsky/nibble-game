#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

//kopiowanie z jednego katalogu do drugiego
void copyToDirectory(const fs::path& from, const fs::path& to)
{
    try 
    {
        fs::copy(from, to, fs::copy_options::recursive);
    }
    catch (const fs::filesystem_error& error)
    {
        std::cerr << "Blad podczas kopiowania: " << error.what() << std::endl;
    }
}


//zwracanie ilosci plikow w katalogu
int countFilesInDirectory(const fs::path& directory)
{
    static int counter = 0;
    for (const fs::directory_entry& entry : fs::directory_iterator(directory))
    {
        if (fs::is_regular_file(entry)) {
            counter++;
        }
    }
    return counter;
}


//szukanie najwiekszego pliku w katalogu
void findLargestFile(const fs::path& directory)
{
    uintmax_t maxFileSize = 0;
    fs::path largestFile;
    for (const fs::directory_entry& entry : fs::directory_iterator(directory))
    {
        if (fs::is_regular_file(entry) && entry.file_size() > maxFileSize)
        {
            maxFileSize = entry.file_size();
            largestFile = entry.path();
        }
    }
    std::cout << "Najwiekszy plik w katalogu: " << largestFile.filename() << " (" << maxFileSize << " bajtow)" << std::endl;
}

//tworzenie listy plikow z danymi rozszerzeniami
void extenstionList(const fs::path& directory, const std::vector<std::string>& extensions)
{
    std::cout << "Lista plików o określonych rozszerzeniach:" << std::endl;
    for (const fs::directory_entry& entry : fs::directory_iterator(directory)) 
        if (fs::is_regular_file(entry))
            for (const auto& ext : extensions) 
                if (entry.path().extension() == ext)
                {
                    std::cout << entry.path().filename() << std::endl;
                    break;
                }
}


//usuwanie pustych katalogow
void removeEmptyDirectories(const fs::path& directory) 
{
    for (const fs::directory_entry& entry : fs::directory_iterator(directory)) 
        if (fs::is_directory(entry))
            if (std::distance(fs::directory_iterator(entry), fs::directory_iterator{}) == 0) 
                fs::remove(entry);
            else
                removeEmptyDirectories(entry);
}

int main()
{ 
    //tworzenie trzech katalogow
    fs::create_directory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit");
    fs::create_directory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit");
    fs::create_directory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit");

    //tworzenie podkatalogow
    fs::create_directory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder1/Subfolder1");
    fs::create_directory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder2/Subfolder2");
    fs::create_directory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3/Subfolder3");

    //tworzenie plikow tekstowych w dwoch podkatalogach
    std::ofstream file1("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder1/Subfolder1/tekstowy1.txt");
    file1 << "plik pierwszy";
    file1.close();
    std::ofstream file2("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder2/Subfolder2/tekstowy2.txt");
    file2 << "plik drugi";
    file2.close();

    removeEmptyDirectories("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3");//

    copyToDirectory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder1","C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3");
    copyToDirectory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder2","C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3");
    std::cout << "\n\nLiczba plikow w subfolderze2: " << countFilesInDirectory("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3/Subfolder2") << "\n\n";
    findLargestFile("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3/Subfolder2");
    std::cout << "\n\n\n";
    std::vector<std::string> extensions;
    extensions.push_back(".txt");
    extensions.push_back(".png");
    extenstionList("C:/Users/grawe/OneDrive - Politechnika Śląska/Pulpit/Folder3/Subfolder2", extensions);
   

    return 0;
}