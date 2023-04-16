#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StayPlace {
    private:
        int stayPlaceNumber;
        bool isOccupied;
        double rate;

    public:
        StayPlace(int stayPlaceNum, bool occupied, double stayPlaceRate) {
            stayPlaceNumber = stayPlaceNum;
            isOccupied = occupied;
            rate = stayPlaceRate;
        }

        int getStayPlaceNumber() {
            return stayPlaceNumber;
        }

        bool getIsOccupied() {
            return isOccupied;
        }

        void setIsOccupied(bool occupied) {
            isOccupied = occupied;
        }

        double getRate() {
            return rate;
        }

        void setRate(double stayPlaceRate) {
            rate = stayPlaceRate;
        }
};

class Booking {
    private:
        string guestName;
        int stayPlaceNumber;
        int numberOfDays;

    public:
        Booking(string name, int stayPlaceNum, int days) {
            guestName = name;
            stayPlaceNumber = stayPlaceNum;
            numberOfDays = days;
        }

        string getGuestName() {
            return guestName;
        }

        int getStayPlaceNumber() {
            return stayPlaceNumber;
        }

        int getNumberOfDays() {
            return numberOfDays;
        }
};

class Hotel {
    private:
        vector<StayPlace> stayPlaces;
        vector<Booking> bookings;

    public:
        Hotel() {
            for (int i = 1; i <= 10; i++) {
                StayPlace newStayPlace(i, false, 100.00);
                stayPlaces.push_back(newStayPlace);
            }
        }

        void displayStayPlaces() {
            for (StayPlace stayPlace : stayPlaces) {
                cout << "Stay Place " << stayPlace.getStayPlaceNumber() << " - ";
                if (stayPlace.getIsOccupied()) {
                    cout << "Occupied" << endl;
                } else {
                    cout << "Available" << endl;
                }
            }
        }

        void makeBooking() {
            string guestName;
            int stayPlaceNumber;
            int numberOfDays;

            cout << "Enter guest name: ";
            cin >> guestName;

            cout << "Enter stay place number: ";
            cin >> stayPlaceNumber;

            cout << "Enter number of days: ";
            cin >> numberOfDays;

            // Check if stay place is available
            auto stayPlace = find_if(stayPlaces.begin(), stayPlaces.end(), [&](StayPlace sp){ return sp.getStayPlaceNumber() == stayPlaceNumber && !sp.getIsOccupied(); });
            if (stayPlace != stayPlaces.end()) {
                // Stay place is available
                stayPlace->setIsOccupied(true);

                Booking newBooking(guestName, stayPlaceNumber, numberOfDays);
                bookings.push_back(newBooking);

                cout << "Booking made successfully." << endl;
            } else {
                // Stay place is not available
                cout << "Stay place is not available." << endl;
            }
        }

        void displayBookings() {
            for (Booking booking : bookings) {
                cout << "Guest Name: " << booking.getGuestName() << endl;
                cout << "Stay Place Number: " << booking.getStayPlaceNumber() << endl;
                cout << "Number of Days: " << booking.getNumberOfDays() << endl;
                cout << endl;
            }
        }

        void checkOut() {
            int stayPlaceNumber;

            cout << "Enter stay place number: ";
            cin >> stayPlaceNumber;

            auto booking = find_if(bookings.begin(), bookings.end(), [&](Booking b){ return b.getRoomNumber() == roomNumber; });
            if (booking != bookings.end()) {
                // Room is occupied and booking exists
                            auto room = find_if(rooms.begin(), rooms.end(), [&](Room r){ return r.getRoomNumber() == roomNumber; });
            if (room != rooms.end()) {
                // Update room status to unoccupied
                room->setIsOccupied(false);

                // Remove booking from list
                bookings.erase(booking);

                cout << "Checkout successful." << endl;
            }
        } else {
            // Room is not occupied or booking does not exist
            cout << "No booking found for room " << roomNumber << endl;
        }
    }
};

int main() {
Hotel hotel;
while (true) {
    int choice;
    cout << "1. Display Rooms" << endl;
    cout << "2. Make Booking" << endl;
    cout << "3. Display Bookings" << endl;
    cout << "4. Check Out" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            hotel.displayRooms();
            break;
        case 2:
            hotel.makeBooking();
            break;
        case 3:
            hotel.displayBookings();
            break;
        case 4:
            hotel.checkOut();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

return 0;}
