import 'package:flutter/material.dart';
import 'package:layoutwidgets/widgets/column_widget.dart';
import 'package:layoutwidgets/widgets/row_widget.dart';
import 'package:layoutwidgets/widgets/stack_widget.dart';

void main() => runApp(LayoutWidgets());

class LayoutWidgets extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      initialRoute:
          '/stack', // Change /stack to /coulumn (to see column widget) and /row (to see column widget)
      routes: {
        '/column': (context) => ColumnWidget(),
        '/row': (context) => RowWidget(),
        '/stack': (context) => StackWidget(),
      },
    );
  }
}
