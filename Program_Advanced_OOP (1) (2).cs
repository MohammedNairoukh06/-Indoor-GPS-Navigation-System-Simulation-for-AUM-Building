//Team memebers:
//Mohammed Nairoukh - 2410205 
//Maya Haddad - 2410064
//Taraf Almajali - 2310371

//Course: Advanced OOP And GUI
//Instructor: Dr. Saif Al Madi
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace Term_Project_Advanced_OOP
{
    internal class Car
    {
        protected string carMaker;
        protected double maxSpeed;
        protected int horsePower;
        public Car(string cm, double ms, int hp)
        {
            carMaker = cm;
            maxSpeed = ms;
            horsePower = hp;
        }
        public override string ToString()
        {
            return "This car is a " + carMaker + "\n"
                 + "Maximum speed: " + maxSpeed + " km/h\n"
                 + "Horsepower: " + horsePower;
        }
    }
    class RaceCar : Car
    {
        public string raceCategory;
        public RaceCar(string carMaker, double maxSpeed, int horsePower, string rc) : base(carMaker, maxSpeed, horsePower)
        {
            raceCategory = rc;
        }
        public string CheckSpeedLevel()
        {
            if (horsePower >= 700)
            {
                return ("High Performance");
            }
            else
            {
                return ("Standard Performance");
            }
        }
        public override string ToString()
        {
            return base.ToString() + "\n" + "Race Category: " + raceCategory;
        }
        static void Main(string[] args)
        {
            RaceCar myRaceCar = new RaceCar("Ferrari", 250, 750, "Formula One");
            //testing the methode of our choice 
            Console.WriteLine("Speed Level: " + myRaceCar.CheckSpeedLevel());
            //printing race car information 
            Console.WriteLine("\nRace car information:");
            Console.WriteLine(myRaceCar.ToString());
        }
    }
}

