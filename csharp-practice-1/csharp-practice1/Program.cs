namespace csharp_practice1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number between 1 and 7 to see its corresponding day of the week: ");
            string? n = Console.ReadLine();
            string message = n switch
            {
                "1" => "Monday\n",
                "2" => "Tuesday\n",
                "3" => "Wednesday\n",
                "4" => "Thursday\n",
                "5" => "Friday\n",
                "6" => "Saturday\n",
                "7" => "Sunday\n",
                _ => "Enter a number between 1 and 7\n"
            };
            Console.WriteLine(message);
        }
    }
}