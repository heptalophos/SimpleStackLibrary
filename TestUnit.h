//---------------------------------------------------------------------------

#ifndef TestUnitH
#define TestUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
#include "BaseStack.h"
#include <FMX.ComboEdit.hpp>
//---------------------------------------------------------------------------

class TTestStackForm : public TForm
{
__published:	// IDE-managed Components
	TButton *PushButton;
	TButton *PopButton;
	TButton *TopButton;
	TButton *IsEmptyButton;
	TButton *LoadButton;
	TButton *CountsButton;
	TEdit *Edit1;
	void __fastcall PushButtonClick(TObject *Sender);
	void __fastcall PopButtonClick(TObject *Sender);
	void __fastcall TopButtonClick(TObject *Sender);
	void __fastcall IsEmptyButtonClick(TObject *Sender);
	void __fastcall LoadButtonClick(TObject *Sender);
	void __fastcall CountsButtonClick(TObject *Sender);
private:	// User declarations
	BaseStack* stack;
    	int count;
	void __fastcall EnableButtons();
public:		// User declarations
	__fastcall TTestStackForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTestStackForm *TestStackForm;
//---------------------------------------------------------------------------
#endif


