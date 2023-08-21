// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "TestUnit.h"

#include "StackOfInt.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TTestStackForm *TestStackForm;
// Holds the name of the dynamic-link library.
const char* library = "StackLibrary.dll";
// type definition for pointer to functions that return (void*)
typedef void* (*VoidReturnFunc)();
// syntax that declares an imported function
extern "C" __declspec(dllimport) void* __stdcall GetClassInstance();

// ---------------------------------------------------------------------------
__fastcall TTestStackForm::TTestStackForm(TComponent* Owner) : TForm(Owner) {
}
//---------------------------------------------------------------------------
void __fastcall TTestStackForm::EnableButtons() {
	PushButton->Enabled = true;
	PopButton->Enabled = true;
	TopButton->Enabled = true;
	IsEmptyButton->Enabled = true;
	CountsButton->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTestStackForm::LoadButtonClick(TObject *Sender) {
	// Dynamically loads the library
	HINSTANCE load = LoadLibrary(library);
	if (load) {
		ShowMessage("Library is loaded!");
		EnableButtons();
		VoidReturnFunc getInstance;
		// GetProcAddress returns a pointer to the loaded method
		getInstance = (VoidReturnFunc)GetProcAddress(load, "GetClassInstance");
		// Invoke GetClassInstance method
		stack = (BaseStack*) getInstance();
		// Note:
		// The BaseStack methods are pure virtual methods, but getInstance() 
		// returns an instance of the Stack class.
		// Wherever we call stack->methodName() later, we are actually calling
		// Stack::methodName(), not BaseStack::methodName().
        this->count = 0;
	}
	else {
		ShowMessage("Sorry, cannot load library!!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TTestStackForm::PushButtonClick(TObject *Sender) {
	if (stack) {
		try {
			int item = StrToInt(Edit1->Text);
			stack->Push(item);
			ShowMessage("Pushed " + IntToStr(item) + " into the stack");
			this->count++;
		}
		catch (const Exception& E) {
			ShowMessage("Please insert an integer!\n\n" + E.Message);
		}
		catch (int E) {
			if (E == 1) {
				ShowMessage("Index out of bounds");
			}
			else {
				ShowMessage(IntToStr(E));
            }
		}
		Edit1->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TTestStackForm::PopButtonClick(TObject *Sender) {
	if (stack) {
		try {
			int item = stack->Pop();
			ShowMessage("Popped " + IntToStr(item));
			this->count--;
		}
		catch (int E) {
			AnsiString Err = "";
			if (E == 1) {
				Err = "Index out of bounds";
			}
			if (E == 2) {
				Err = "Stack is Empty";
			}
//			ShowMessage("Exception " + IntToStr(Exception));
			ShowMessage(Err);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTestStackForm::TopButtonClick(TObject *Sender) {
	if (stack) {
		try {
			int item = stack->Top();
			ShowMessage("The top of the stack is " + IntToStr(item));
		}
		catch (int E) {
			AnsiString Err = "";
			if (E == 1) {
				Err = "Index out of bounds";
			}
			if (E == 2) {
				Err = "Stack is Empty";
			}
			ShowMessage(Err);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTestStackForm::IsEmptyButtonClick(TObject *Sender) {
	if (stack) {
		if (stack->IsEmpty()) {
			ShowMessage("Yes, the stack is empty!");
		}
		else {
			ShowMessage("No, stack is NOT empty!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TTestStackForm::CountsButtonClick(TObject *Sender) {
	if (stack) {
		try {
			int cnt = this->count;
			AnsiString msg = stack->IsEmpty()
							 ? "There are no items in the stack"
							 : "There are currently " +
								IntToStr(cnt) +
							   " items in the stack";
			ShowMessage(msg);
		}
		catch (const Exception& E) {
			ShowMessage(E.Message);
		}
	}
}
//---------------------------------------------------------------------------

