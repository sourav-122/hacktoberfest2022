import 'package:flutter/material.dart';

void main() => runApp(RowWidget());

class RowWidget extends StatelessWidget {
  Widget build(BuildContext) {
    return MaterialApp(
      home: SampleCode(),
    );
  }
}

Widget SampleCode() {
  final imageUrl =
      'https://media.istockphoto.com/vectors/woman-with-laptop-sitting-in-nature-and-leaves-concept-illustration-vector-id1139913278?k=6&m=1139913278&s=612x612&w=0&h=vDks140zgZAaCDrxSW0C4IabyHQI7aM8uw0MfM7gMrs=';
  return Scaffold(
    backgroundColor: Colors.grey[300],
    body: Padding(
      padding: EdgeInsets.symmetric(vertical: 60.0, horizontal: 10.0),
      child: Container(
        height: 100.0,
        width: 400.0,
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(10.0),
        ),
        child: Padding(
          padding: EdgeInsets.symmetric(horizontal: 10),
          child: Row(
            // mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              ClipRRect(
                borderRadius: BorderRadius.circular(10),
                child: Image.network(
                  imageUrl,
                  width: 80,
                  height: 80,
                  fit: BoxFit.cover,
                ),
              ),
              SizedBox(width: 10),
              Expanded(
                child: Text(
                  'Design',
                  style: TextStyle(color: Colors.grey[800], fontSize: 22),
                ),
              ),
              Container(
                height: 80,
                width: 80,
                decoration: BoxDecoration(
                  color: Colors.blue[900],
                  borderRadius: BorderRadius.circular(10),
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      '11',
                      style: TextStyle(
                        color: Colors.grey[300],
                        fontSize: 22,
                      ),
                    ),
                    Text(
                      'quizzes',
                      style: TextStyle(
                        color: Colors.grey[300],
                        fontSize: 16,
                      ),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    ),
  );
}

// #######################  Code 2  #######################
// Widget SampleCode() {
//   final imageUrl =
//       'https://media.istockphoto.com/vectors/woman-with-laptop-sitting-in-nature-and-leaves-concept-illustration-vector-id1139913278?k=6&m=1139913278&s=612x612&w=0&h=vDks140zgZAaCDrxSW0C4IabyHQI7aM8uw0MfM7gMrs=';
//   return Scaffold(
//     backgroundColor: Colors.grey[300],
//     body: Padding(
//       padding: EdgeInsets.symmetric(vertical: 60.0, horizontal: 10.0),
//       child: Container(
//         height: 100.0,
//         width: 400.0,
//         decoration: BoxDecoration(
//           color: Colors.white,
//           borderRadius: BorderRadius.circular(10.0),
//         ),
//         child: Row(
//           mainAxisAlignment: MainAxisAlignment.spaceAround,
//           children: [
//             ClipRRect(
//               borderRadius: BorderRadius.circular(10),
//               child: Image.network(
//                 imageUrl,
//                 width: 80,
//                 height: 80,
//                 fit: BoxFit.cover,
//               ),
//             ),
//             Text(
//               'Design',
//               style: TextStyle(color: Colors.grey[800], fontSize: 22),
//             ),
//             SizedBox(width: 30),
//             Container(
//               height: 80,
//               width: 80,
//               decoration: BoxDecoration(
//                 color: Colors.blue[900],
//                 borderRadius: BorderRadius.circular(10),
//               ),
//               child: Column(
//                 mainAxisAlignment: MainAxisAlignment.center,
//                 children: [
//                   Text(
//                     '11',
//                     style: TextStyle(
//                       color: Colors.grey[300],
//                       fontSize: 22,
//                     ),
//                   ),
//                   Text(
//                     'quizzes',
//                     style: TextStyle(
//                       color: Colors.grey[300],
//                       fontSize: 16,
//                     ),
//                   ),
//                 ],
//               ),
//             ),
//           ],
//         ),
//       ),
//     ),
//   );
// }

// ###########################  Code 1  ###########################
// Widget SampleCode() {
//   final rowIcons = [
//     Icon(Icons.cake),
//     Icon(Icons.local_drink),
//     Icon(Icons.icecream),
//     Icon(Icons.no_meals),
//   ];
//   int iconIndex = 0;

//   return Scaffold(
//     backgroundColor: Color.fromRGBO(222, 229, 227, 1),
//     body: Padding(
//       padding: EdgeInsets.symmetric(horizontal: 16.0, vertical: 60),
//       child: SingleChildScrollView(
//         scrollDirection: Axis.horizontal,
//         child: Container(
//           // to add extra space around row so that shadow will be visible clearly
//           // extra height, child container's height is 60. So we have given parent container height of 70
//           height: 70,
//           child: Row(
//             children: [
//               for (int i = 0; i < 5; i++)
//                 Padding(
//                   padding: EdgeInsets.only(left: 10.0, right: 20.0),
//                   child: Container(
//                     height: 60.0,
//                     width: 60.0,
//                     decoration: BoxDecoration(
//                       color: (i != 4)
//                           ? Colors.white
//                           : Color.fromRGBO(122, 164, 146, 1),
//                       borderRadius: BorderRadius.circular(30),
//                       boxShadow: [
//                         BoxShadow(
//                           color: Colors.black.withOpacity(0.25),
//                           blurRadius: 5,
//                           spreadRadius: 0.1,
//                         )
//                       ],
//                     ),
//                     child: (i < 4)
//                         ? rowIcons[iconIndex++]
//                         : Center(
//                             child: Text('All',
//                                 style: TextStyle(
//                                   color: Colors.white,
//                                   fontSize: 18,
//                                 ))),
//                   ),
//                 ),
//               // SizedBox(width: 40.0),       // do not work because first loop will render all containers and then gives width of 40 pixels. So we will wrap container with Padding()
//             ],
//           ),
//         ),
//       ),
//     ),
//   );
// }
