#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Maximum number of symptoms
const int MAX_SYMPTOMS = 10;

// Maximum length of symptom name
const int MAX_SYMPTOM_LENGTH = 50;

// Maximum length of patient name
const int MAX_NAME_LENGTH = 50;

// Structure to represent patient information
struct Patient
{
  string name;
  string middleName;
  string phoneNumber;
  string address;
  int age;
  float weight;
  float bodyTemperature;
  string bloodPressure;
  vector<string> symptoms;
  string disease;
  string prescription;
};

class MedicalAssistant
{
public:
  // Function to register a new patient
  void registerPatient();

  // Function to record data and symptoms for a patient
  void recordDataAndSymptoms();

  // Function to predict disease based on symptoms
  void predictDisease(Patient &patient);

private:
  // Function to save patient data to file
  void saveToFile(const Patient &patient);

  // Function to get symptoms from the user
  void getSymptomsFromUser(Patient &patient);
};

void MedicalAssistant::registerPatient()
{
  Patient patient;
  cout << "Enter patient name: ";
  getline(cin, patient.name);
  cout << "Enter patient middle name: ";
  getline(cin, patient.middleName);
  cout << "Enter patient phone number: ";
  getline(cin, patient.phoneNumber);
  cout << "Enter patient address: ";
  getline(cin, patient.address);
  cout << "Enter patient age: ";
  cin >> patient.age;
  cout << "Enter patient weight: ";
  cin >> patient.weight;
  cout << "Enter patient body temperature in degree Celcius C: ";
  cin >> patient.bodyTemperature;
  cout << "Enter patient blood pressure in millimeter mercury (mmHg): ";
  cin.ignore();
  getline(cin, patient.bloodPressure);

  cout << "----------------------------------------------------------------------------------" << endl;
  cout << "Choose symptoms (separate by comma, 0 to stop): " << endl;
  cout << "1. Fatigue" << endl;
  cout << "2. Fever" << endl;
  cout << "3. Vomiting" << endl;
  cout << "4. Pain" << endl;
  cout << "5. Shortness of breath" << endl;
  cout << "6. Loss of appetite" << endl;

  // Get symptoms from user
  getSymptomsFromUser(patient);

  // Predict disease based on symptoms
  predictDisease(patient);

  // Save patient data to file
  saveToFile(patient);
}

void MedicalAssistant::predictDisease(Patient &patient)
{
  // Placeholder function, actual implementation will require more sophisticated logic
  // For simplicity, we're just taking the first symptom and making a prediction based on it
  if (!patient.symptoms.empty())
  {
    string firstSymptom = patient.symptoms[0];
    if (firstSymptom == "Fatigue")
    {
      patient.disease = "Chronic Fatigue Syndrome";
      patient.prescription = "Rest, hydration, and symptom management.";
    }
    else if (firstSymptom == "Fever")
    {
      patient.disease = "Influenza (Flu)";
      patient.prescription = "Antiviral medication, rest, and hydration.";
    }
    else if (firstSymptom == "Vomiting")
    {
      patient.disease = "Gastroenteritis (Stomach Flu)";
      patient.prescription = "Hydration, electrolyte replacement, and antiemetic medication.";
    }
    else if (firstSymptom == "Pain")
    {
      patient.disease = "Muscle Strain";
      patient.prescription = "Rest, ice, compression, and elevation (RICE therapy).";
    }
    else if (firstSymptom == "Shortness of breath")
    {
      patient.disease = "Asthma";
      patient.prescription = "Bronchodilators, corticosteroids, and avoiding triggers.";
    }
    else if (firstSymptom == "Loss of appetite")
    {
      patient.disease = "Gastritis";
      patient.prescription = "Antacids, proton pump inhibitors, and dietary changes.";
    }
    else
    {
      patient.disease = "Unknown";
      patient.prescription = "Please consult a medical professional for diagnosis and treatment.";
    }
  }
  else
  {
    patient.disease = "Unknown";
    patient.prescription = "No symptoms provided. Please consult a medical professional.";
  }
  // Print prediction and prescription
  cout << "----------------------------------------------------------------------------------" << endl;
  cout << "Predicted disease based on symptoms: " << patient.disease << endl;
  cout << "Prescription: " << patient.prescription << endl;
}
void MedicalAssistant::saveToFile(const Patient &patient)
{
  // Construct filename using patient's name
  string filename = patient.name + ".txt";

  // Open file for writing
  ofstream file(filename);

  // Write patient data to file
  file << "Name: " << patient.name << endl;
  file << "Middle Name: " << patient.middleName << endl;
  file << "Phone Number: " << patient.phoneNumber << endl;
  file << "Address: " << patient.address << endl;
  file << "Age: " << patient.age << endl;
  file << "Weight: " << patient.weight << endl;
  file << "Body Temperature degree Celcius C: " << patient.bodyTemperature << endl;
  file << "Blood Pressure in millimeter mercury (mmHg): " << patient.bloodPressure << endl;

  // Write symptoms to file
  file << "Symptoms:" << endl;
  for (const string &symptom : patient.symptoms)
  {
    file << "- " << symptom << endl;
  }

  // Write disease and prescription to file
  file << "Disease: " << patient.disease << endl;
  file << "Prescription: " << patient.prescription << endl;

  // Close the file
  file.close();

  cout << "Patient data saved to file: " << filename << endl;
}

void MedicalAssistant::getSymptomsFromUser(Patient &patient)
{
  int numSymptoms;
  cout << "Enter the number of symptoms you feel right know from the list: ";
  cin >> numSymptoms;
  cin.ignore();
  cout << "----------------------------------------------------------------------------------" << endl;

  if (numSymptoms > 0 && numSymptoms <= MAX_SYMPTOMS)
  {
    for (int i = 0; i < numSymptoms; i++)
    {
      cout << "Enter symptom " << (i + 1) << ": ";
      string symptom;
      getline(cin, symptom);
      patient.symptoms.push_back(symptom);
    }
  }
  else
  {
    cout << "Invalid number of symptoms. Please try again." << endl;
  }
}

int main()
{
  MedicalAssistant assistant;
  if (true)
  {
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "-------------------WELCOME TO ANAF DIGITAL MEDICAL ASSISTANT-----------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "-                              I CAN HELP YOU BY                                  -" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "-                   => Storing your data for medical Purpose.                    -" << endl;
    cout << "-                   => Record Your symptoms and analyse it.                      -" << endl;
    cout << "-                   => Predict Your Disease based on your symptom                -" << endl;
    cout << "-                   => Giving you prescription for disease                -" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    assistant.registerPatient();
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "THANK YOU FOR USING ANAF DIGITAL MEDICAL ASSISTANT. Goodbye!" << endl;
  }
  else
  {
    cout << "Invalid choice. Please try again." << endl;
  }

  return 0;
}