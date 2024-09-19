public class Person {
    // Private fields
    private String name;
    
    private int age;

    // Static field to keep track of the total number of Person objects
    private static int totalPeople = 0;

    // Constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
        totalPeople++; // Increment the count when a new Person is created
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Setter for name
    public void setName(String name) {
        this.name = name;
    }

    // Getter for age
    public int getAge() {
        return age;
    }

    // Setter for age
    public void setAge(int age) {
        this.age = age;
    }

    // Method to display the name
    public void displayName() {
        System.out.println("Name: " + name);
    }

    // Method to display the age
    public void displayAge() {
        System.out.println("Age: " + age);
    }

    // Static method to get the total number of Person objects
    public static int getTotalPeople() {
        return totalPeople;
    }

    public static void main(String[] args) {
        // Create new Person objects
        Person person1 = new Person("Alice", 30);
        Person person2 = new Person("Bob", 25);
        Person person3 = new Person("Charlie", 35);

        // Display the name and age for each person
        person1.displayName();
        person1.displayAge();
        
        person2.displayName();
        person2.displayAge();

        person3.displayName();
        person3.displayAge();

        // Print the total number of Person objects
        System.out.println("Total number of people: " + Person.getTotalPeople());
    }
}
