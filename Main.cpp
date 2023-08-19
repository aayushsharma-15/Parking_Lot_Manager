#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include"ParkingLot.cpp"
#include"FeeCalculator.cpp"

int main() {
   
    ParkingLot parking_lot;
    Vehicle vehicle;
    FeeCalculator fee_calculator;
   queue<Vehicle> four_wheeler_queue;

    int choice;
    
    while (true) {
       cout<<endl;
       cout << "Parking Lot Management System" <<endl;
       cout << "1. Enter Parking Lot" <<endl;
       cout << "2. Exit Parking Lot" <<endl;
       cout << "3. Calculate Fee" <<endl;
       cout << "4. Check Availability" <<endl;
       cout << "5. Live Status" <<endl;
       cout << "6. Exit" <<endl;
       cout<<endl;
       cout << "Enter your choice: ";
       cin >> choice;
       cout<<endl;
       


        switch (choice) {
            case 1:{
               string license_plate;
               string owner_name;
               cout << "Enter license_plate: "<<endl;
               cin >> license_plate;
               cout << "Enter owners name: "<<endl;
               cin >> owner_name;
    

                vehicle.setDetails(license_plate,owner_name) ;
            
                 if (parking_lot.is_space_available() ){

                      int spot_number= parking_lot.allocate_parking_spot(vehicle);

                    if (spot_number != -1) {
                        cout << "parking spot alloted !!"<<endl;
                         cout<<"  For license plate = "<< vehicle.getLicensePlate() <<endl;
                       cout<< " Your spot number is " << spot_number <<endl;
                    } 
                    else {
                     cout << "No available parking spot." <<endl;
                    }

                    }
                else {
                        four_wheeler_queue.push(vehicle);
                       cout << "No space vacant, Please wait for your turn." <<endl;
                       cout << "You are number " << four_wheeler_queue.size()<<" in the waiting list" <<endl;
                       cout << "Thank you "<<endl;

                }

            break;
            }

            case 2:{

            int spot_number;
            int parked_hours;
            cout<<"Enter your spot Number :";
            cin>>spot_number;

               
                  bool exit_temp = parking_lot.deallocate_parking_spot(spot_number);

                if(exit_temp){
                    
                       cout << "Parked my vehicle in spot number "<<spot_number << "for less than __ hours"<<endl; 
                       cin >> parked_hours;
                       cout<<endl;
        

                     cout<<"****************fee slip****************"<<endl;
                     cout<<endl;

                     Vehicle vehicle_temp = parking_lot.getVehicleAtSpot(spot_number);
                    
                    if (!vehicle_temp.getLicensePlate().empty()) {
                    cout << "License Plate: " << vehicle_temp.getLicensePlate() <<endl;
                    cout<<endl;
                    cout << "Owner: " << vehicle_temp.getOwnerName() <<endl;
                    }
                    cout<<endl;
                     double total_fee = fee_calculator.calculate_fee(parked_hours);
                    cout << "Total fee: " << total_fee << " rp" <<endl;
                    

                    if(!four_wheeler_queue.empty()){

                    spot_number= parking_lot.allocate_parking_spot(four_wheeler_queue.front());

                     cout << "vehicle waiting for spot allocated !!"<<endl;
                     cout<<"  license plate = "<< four_wheeler_queue.front().getLicensePlate() <<endl;
                     cout<< " spot number is " << spot_number <<endl;
                       
                        four_wheeler_queue.pop();
                }
               
                }
                else{
                    cout<<"Invalid spot number or already vacant"<<endl;
                }
             break;
            }

            case 3:
            {
                  int parked_hours;
                    cout<<endl;
                    cout<<"*****Charges*****"<<endl;
                    cout<<"Base charge = 20 rp"<<endl;
                    cout<<"Less than 1 hour = Base charge + 0 rp"<<endl;
                    cout<<"Less than 2 hour = Base charge + 10 rp"<<endl;
                    cout<<"Less than 3 hour = Base charge + 50 rp"<<endl;
                    cout<<"More than 3 hour = penalty"<<endl;
                       cout << "Parking requirment for less than __hours"<<endl; 
                       cin >> parked_hours;
                       cout<<endl;

                        double total_fee = fee_calculator.calculate_fee(parked_hours);
                       cout << "Total fee: " << total_fee << " rp" <<endl;

                 break;
            }

            case 4:{  

            cout << "Vacant spots: " << parking_lot.getNumVacantSpots() << endl;
            cout << "Occupied spots: " << parking_lot.getNumOccupiedSpots() << endl;

               bool available_temp= parking_lot.is_space_available();
               if(available_temp){
                cout<<"Space is vacant ,You can enter the parking lot "<<endl;
               }
               else{
                cout<<"No space vacant, Please enter the parking lot and wait for your turn."<<endl;
               }

            break;
              }


            case 5:{
                parking_lot.print_spot_status();
                break;
            }

            case 6:{
               cout << "Exiting program." <<endl;
                return 0;
            }

            default:{
               cout << "Invalid choice. Please enter a valid option." <<endl;
            }
        }
    }

    return 0;
}


