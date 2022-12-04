using System;
using System.Net;
using System.Net.Http.Json;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.IO;

namespace SendToServer;
class Program
{
    static async Task Main(string[] args)
    {
        var random = new Random();
        int length = random.Next(20, 101); //returns random number between 20-100
        int sortMethod = random.Next(0, 2);
        int[] inputArray = new int[length];

        Console.WriteLine($"The number of elements in the array: {length}\n");
        
        fillArray(inputArray);
        switch (sortMethod)
        {
            case 0:
                Console.WriteLine("Applying 'Counting Sort' Algorithm:");
                CountingSort(inputArray);
                break;
            case 1:
                Console.WriteLine("Applying 'Quick Sort' Algorithm:");
                int low = 0;
                int high = inputArray.Length - 1;
                quickSort(inputArray, low, high); //left partition
                break;
            default:
                Console.WriteLine("Applying C# internal 'Array.Sort()' Algorithm:");
                Array.Sort(inputArray);
                break;
        }
        printArray(inputArray);

        await Send(inputArray);
    }

    static void CountingSort(int[] array)
    {
        if (array.Length == 0)
        {
            return;
        }

        // Determine minimum and maximum values
        int minValue = array[0];
        int maxValue = array[0];
        for (int i = 1; i < array.Length; i++)
        {
            if (array[i] < minValue)
            {
                minValue = array[i];
            }
            else if (array[i] > maxValue)
            {
                maxValue = array[i];
            }
        }

        CountingSort(array, minValue, maxValue);
    }

    static void CountingSort(int[] array, int minValue, int maxValue)
    {
        int[] buckets = new int[maxValue - minValue + 1];

        for (int i = 0; i < array.Length; i++)
        {
            buckets[array[i] - minValue]++;
        }

        int sortedIndex = 0;
        for (int i = 0; i < buckets.Length; i++)
        {
            while (buckets[i] > 0)
            {
                array[sortedIndex++] = i + minValue;
                buckets[i]--;
            }
        }
    }

    private static void quickSort(int[] arr, int low, int high)
    {
        if (low < high)
        {
            int indexOfPivot = partition(arr, low, high);
            quickSort(arr, low, indexOfPivot - 1); //left partition
            quickSort(arr, indexOfPivot + 1, high); //right partition
        }
    }

    private static int partition(int[] arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        for (int index = low; index < high; index++)
        {
            if (arr[index] <= pivot)
            {
                i++;
                //swap arr[i] and arr[index]
                (arr[i], arr[index]) = (arr[index], arr[i]);
            }
        }

        //swap arr[i+1] and arr[pivot]
        (arr[i + 1], arr[high]) = (arr[high], arr[i + 1]);

        return i + 1;
    }

    //Generate and print array:
    static void fillArray(int[] array)
    {
        var length = array.Length;
        var random = new Random();
        for (int i = 0; i < length; i++)
        {
            array[i] = random.Next(-100, 101);
            Console.Write($"{array[i]} ");
        }
        Console.WriteLine("\n");
    }
    static void printArray(int[] array)
    {
        int length = array.Length;
        for (int i = 0; i < length; i++)
        {
            Console.Write($"{array[i]} ");
        }
        Console.WriteLine("\n");
    }
    
    static async Task Send(int[] array)
    {
        using var settingsFile = System.IO.File.OpenRead("external.json");
        var settings = JsonSerializer.Deserialize<Settings>(settingsFile);
        string url = settings.url ?? String.Empty;
        string param = settings.param ?? String.Empty;
        string result = string.Join(" ", array);

        if (url != String.Empty) { 
            var client = new HttpClient();
            HttpContent content = new StringContent(result, Encoding.UTF8, "application/json");
            try
            {
                Console.WriteLine($"Attempting to send the array to the {url} \n");
                HttpResponseMessage response = await client.PostAsync(url + param, content);
                response.EnsureSuccessStatusCode();
                string responseBody = await response.Content.ReadAsStringAsync();
                Console.WriteLine("{0} \n", responseBody);
            }
            catch (HttpRequestException e)
            {
                Console.WriteLine("Message :{0} \n", e.Message);
            }
        }
        else
            {
                Console.WriteLine("URL cannot be empty. Please check your external.json contents \n");
            }
    }
    public class Settings
    {
        public string? url { get; set; }
        public string? param { get; set; }
    }
}