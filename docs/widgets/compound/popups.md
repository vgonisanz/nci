# Popups

NCI provide different popups in order to display messages:

* [Popup](compound/popup)
* [WarningPopup](buttons/warningpopup)
* [ErrorPopup](buttons/errorpopup)

## Requirements

* REQ-PUP-001: A popup shall appear always in the highest position in the manager stack.
* REQ-PUP-002: A popup shall draw a box to limit it.
* REQ-PUP-003: A popup shall be drawn in the centre of the main screen.
* REQ-PUP-004: A popup shall be destroy when lost focus, and focus cannot change to other frame.
* REQ-PUP-005: A popup shall provide a way to exit, and select a button if required.
* REQ-PUP-006: Popup default exit key will be q.
* REQ-PUP-007: A popup shall contain a text field to show a text.
* REQ-PUP-008: A raw popup shall contain no buttons.
* REQ-PUP-009: A warning popup shall contain only OK button.
* REQ-PUP-010: A error popup shall contain OK button and cancel button.
* REQ-PUP-011: A help popup shall toggle using h keybinding by default in each VirtualFrame with keybinding assignment.