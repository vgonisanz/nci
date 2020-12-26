# Widgets

## General purpose widgets

* [Interfaces manager](widgets/imanager): Section with the info to render the whole screen.
* [Frames](widgets/frames): Section with the basic drawable widget.

## Basic widgets

A basic widget is a simple widget to isolate a small behavior.

* [Text](widgets/basics/textframe): Read-only or editable text widget with different purposes.
* [Buttons](widgets/basics/buttons): A collection of different button widgets.
* [Image](widgets/basics/image): A friendly way to display images in the terminal.
* [Progress Bar](widgets/basics/progressbar): **TODO design update flow**

## Compound widget

A compound widget is a complete, self-contained, reusable widget sub-tree of widgets with a specific behavior.

* [Popup](widgets/compounds/popup): A collection of different popup widgets with different purposes.
* [Menu](widgets/compounds/menu): **TODO**
* [Toolbar](widgets/compounds/toolbar): **TODO**
* [List](widgets/compounds/list): **TODO**

## Complex compound widget

This is and advanced compound widget to solve a well known problem type or use case.

* [Books](widgets/complex/books): A collection of different books widgets.

## Other requirements **TODO**

* REQ-GEN-0000X: (TBD) A DynamicFrame object shall manage movable, resizable window.
* REQ-GEN-0000X: (TBD) Thread helper to create parallel task for use in samples / help users.
