//PLEASE RUN THIS ON YOUR ANDROID STUDIO IDE , THANK YOU :))
//CASE : if u purchase less than 50000, u got no discount
//CASE : if u purchase in range 50000 to 100000 , u got 10% discount
//CASE : if u purchase in range 100000 to 200000 , u got 15% discount
//CASE : if u purchase greater than 200000 , u got 25% discount

import java.util.Scanner

fun main(args: Array<String>) {

    fun something() {


        // Creates an instance which takes input from standard input (keyboard)
        val reader = Scanner(System.`in`)


        print("Enter total purchase: ")

        // nextInt() reads the next integer from the keyboard
        val totalpurchase: Int = reader.nextInt()


        val disk10d:Double = 10.0/100.0
        val disk15d:Double = 15.0/100.0
        val disk25d:Double = 25.0/100.0

        val disc10 =  disk10d * totalpurchase

        val disc15 =  disk15d * totalpurchase

        val disc25 = disk25d * totalpurchase





        when {
            totalpurchase < 50000 -> println(
                "you got no discount : 0 \n"+ "Amount to be paid = $totalpurchase"
            )
            totalpurchase in 50000..100000 -> println(
                "u got 10% discount : ${disc10.toInt()} \n"+ "Amount to be paid = ${totalpurchase - disc10.toInt()}"
            )
            totalpurchase in 100000..200000 -> println(
                "u got 15% discount : ${disc15.toInt()} \n"+ "Amount to be paid = ${totalpurchase - disc15.toInt()}"
            )
            totalpurchase > 200000 -> println(
                "u got 25% discount : ${disc25.toInt()} \n"+"Amount to be paid = ${totalpurchase - disc25.toInt()}"
            )
            else -> {
                println("please enter correct input!")
            }
        }

    }




    something()


}

