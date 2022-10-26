// import 'dart:ui';

import 'package:flutter/material.dart';

class ColumnWidget extends StatelessWidget {
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        body: SampleCard(),
      ),
    );
  }
}

Widget SampleCard() {
  return Center(
    child: Column(
      // without this column, the container will be places at center of screen, but now its is at center and top of column
      children: [
        Padding(
          padding: EdgeInsets.symmetric(vertical: 20.0),
          child: ClipRRect(
            borderRadius: BorderRadius.circular(10),
            child: Container(
              width: 180,
              height: 230,
              color: Color.fromRGBO(39, 38, 44, 1),
              // decoration: BoxDecoration(
              //   color: Color.fromRGBO(39, 38, 44, 1),
              //   borderRadius: BorderRadius.circular(10),
              // ),
              child: Padding(
                padding: EdgeInsets.all(12),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Image.network(
                      "http://pngimg.com/uploads/burger_sandwich/burger_sandwich_PNG4133.png",
                    ),
                    SizedBox(height: 20.0),
                    Text(
                      'Beef Burger',
                      style: TextStyle(
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                        color: Colors.white,
                      ),
                    ),
                    SizedBox(height: 8),
                    Text(
                      'Onion with cheese',
                      style: TextStyle(
                        fontSize: 14,
                        color: Colors.white,
                      ),
                    ),
                    SizedBox(height: 8),
                    Row(
                      children: [
                        Text(
                          '\$18.00',
                          style: TextStyle(
                            fontSize: 14.0,
                            fontWeight: FontWeight.bold,
                            color: Colors.white,
                          ),
                        ),
                        SizedBox(width: 60),
                        Container(
                          decoration: BoxDecoration(
                              color: Colors.black,
                              borderRadius: BorderRadius.circular(8)),
                          child: Icon(Icons.add, color: Colors.white, size: 16),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          ),
        ),
      ],
    ),
  );
}



// Container(
//         decoration: BoxDecoration(
//           image: DecorationImage(image: NetworkImage(imgUrl), fit: BoxFit.cover),
//         ),
//         child: BackdropFilter(
//             filter: ui.ImageFilter.blur(sigmaX: 4.0, sigmaY: 4.0),
//             child: Container(
//               decoration: BoxDecoration(color: Colors.white.withOpacity(0.0)),
//             ),
//           ),
//       );

// Widget SampleCard2a() {
//   return Center(
//     child: Padding(
//       padding: EdgeInsets.all(20),
//       child: Container(
//         width: 180,
//         height: 180,
//         decoration: BoxDecoration(
//           gradient: LinearGradient(
//             begin: Alignment.topLeft,
//             end: Alignment.bottomRight,
//             colors: [Colors.indigo, Colors.white],
//           ),
//           color: Colors.white.withOpacity(0.35),
//           borderRadius: BorderRadius.circular(30),
//         ),
//         child: Column(
//           mainAxisAlignment: MainAxisAlignment.center,
//           children: [
//             Icon(
//               Icons.access_time,
//               size: 45,
//               color: Colors.blue[100],
//             ),
//             SizedBox(height: 10),
//             Text(
//               'Active',
//               style: TextStyle(
//                 color: Colors.white,
//                 fontWeight: FontWeight.bold,
//                 fontSize: 20,
//               ),
//             ),
//             SizedBox(height: 5),
//             Text(
//               '2 Times a day',
//               style: TextStyle(
//                 color: Colors.blue[50],
//                 fontSize: 13,
//               ),
//             ),
//           ],
//         ),
//       ),
//     ),
//   );
// }


// Widget SampleCard2b() {
//   return Center(
//     child: Padding(
//       padding: EdgeInsets.all(20),
//       child: Container(
//         width: 180,
//         height: 180,
//         decoration: BoxDecoration(
//           color: Colors.indigo[900],
//           borderRadius: BorderRadius.circular(30),
//         ),
//         child: Column(
//           mainAxisAlignment: MainAxisAlignment.center,
//           children: [
//             Icon(
//               Icons.access_time,
//               size: 45,
//               color: Colors.blue[100],
//             ),
//             SizedBox(height: 10),
//             Text(
//               'Active',
//               style: TextStyle(
//                 color: Colors.white,
//                 fontWeight: FontWeight.bold,
//                 fontSize: 20,
//               ),
//             ),
//             SizedBox(height: 5),
//             Text(
//               '2 Times a day',
//               style: TextStyle(
//                 color: Colors.blue[50],
//                 fontSize: 13,
//               ),
//             ),
//           ],
//         ),
//       ),
//     ),
//   );
// }

// Widget SampleCard2c() {
//   return Center(
//     child: Padding(
//       padding: EdgeInsets.all(20),
//       child: SizedBox(
//         // SizedBox() will also work but we want border radius, so we are using container
//         height: 180,
//         width: 180,
//         child: Card(
//           color: Colors.indigo[900],
//           elevation: 5,
//           shape: RoundedRectangleBorder(
//             // to give borderradius to card
//             borderRadius: BorderRadius.circular(30),
//           ),
//           child: Column(
//             mainAxisAlignment: MainAxisAlignment.center,
//             children: [
//               Icon(
//                 Icons.access_time,
//                 size: 45,
//                 color: Colors.blue[100],
//               ),
//               SizedBox(height: 10),
//               Text(
//                 'Active',
//                 style: TextStyle(
//                   color: Colors.white,
//                   fontWeight: FontWeight.bold,
//                   fontSize: 20,
//                 ),
//               ),
//               SizedBox(height: 5),
//               Text(
//                 '2 Times a day',
//                 style: TextStyle(
//                   color: Colors.blue[50],
//                   fontSize: 13,
//                 ),
//               ),
//             ],
//           ),
//         ),
//       ),
//     ),
//   );
// }
















// Widget SampleCard1() {
//   final imageUrl =
//       "https://helpx.adobe.com/content/dam/help/en/photoshop/using/convert-color-image-black-white/jcr_content/main-pars/before_and_after/image-before/Landscape-Color.jpg";
//   // "https://images.wallpapersden.com/image/download/beach-minimalist-digital-art-5k_bGpoZ2WUmZqaraWkpJRnamtlrWZsZWU.jpg";
//   return Center(
//     child: Column(
//       children: [
//         Padding(
//           // to give padding above and below the card
//           padding: EdgeInsets.symmetric(vertical: 20),
//           child: Container(
//             height: 200,
//             width: 300,
//             decoration: BoxDecoration(
//               color: Colors.blue,
//               borderRadius: BorderRadius.circular(10),
//               image: DecorationImage(
//                 image: NetworkImage(imageUrl),
//                 fit: BoxFit.cover,
//                 colorFilter: ColorFilter.mode(
//                   // Color.fromRGBO(0, 0, 0, 0.25),
//                   Colors.black.withOpacity(0.25),
//                   BlendMode.darken,
//                 ),
//               ),
//             ),
//             child: Padding(
//               // to give padding to text inside card
//               padding: EdgeInsets.only(left: 20, top: 20),
//               child: Column(
//                 crossAxisAlignment: CrossAxisAlignment.start,
//                 children: [
//                   Text(
//                     'A-frame',
//                     style: TextStyle(
//                       fontSize: 22,
//                       fontWeight: FontWeight.bold,
//                       color: Colors.white,
//                     ),
//                   ),
//                   SizedBox(height: 10),
//                   Text(
//                     '80-120\$',
//                     style: TextStyle(
//                       fontSize: 28,
//                       color: Colors.white,
//                     ),
//                   ),
//                 ],
//               ),
//             ),
//           ),
//         ),
//       ],
//     ),
//   );
// }
