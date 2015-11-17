
#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

namespace MSNCP
{
	public ref class Window : public System::Windows::Forms::Form
	{
	public:
		Window(void)
		{
			InitializeComponent();
			//CONSTRUÇÃO
		}

	protected:
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}


	protected: 















































	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
































































































private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::ListBox^  listBox1;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::TabPage^  tabPage6;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::Label^  label38;


private: System::Windows::Forms::GroupBox^  hEvent;


private: System::Windows::Forms::GroupBox^  bEvent;


private: System::Windows::Forms::CheckBox^  isHevent;
private: System::Windows::Forms::CheckBox^  isBevent;
private: System::Windows::Forms::Button^  hEventEnd;

private: System::Windows::Forms::Button^  bEventStart;
private: System::Windows::Forms::Button^  bEventEnd;
private: System::Windows::Forms::Button^  hEventStart;

private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::CheckBox^  isVIP;
private: System::Windows::Forms::Button^  userSelect;



private: System::Windows::Forms::GroupBox^  groupBox6;

private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::TextBox^  userAccount;
private: System::Windows::Forms::NumericUpDown^  userCredits;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::CheckBox^  userIsVIP;
private: System::Windows::Forms::Button^  userUpdate;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::CheckBox^  isVIPSystem;
private: System::Windows::Forms::NumericUpDown^  vMonthPrice;




private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::NumericUpDown^  numericUpDown9;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::NumericUpDown^  vItemDrop;


private: System::Windows::Forms::NumericUpDown^  vExperience;
























private: System::Windows::Forms::TabPage^  WhisperMode;




























private: System::Windows::Forms::TabControl^  tabControl1;

private: System::Windows::Forms::TabPage^  tabPage4;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::Timer^  timer1;
private: System::ComponentModel::IContainer^  components;
private:void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->hEvent = (gcnew System::Windows::Forms::GroupBox());
			this->hEventEnd = (gcnew System::Windows::Forms::Button());
			this->hEventStart = (gcnew System::Windows::Forms::Button());
			this->bEvent = (gcnew System::Windows::Forms::GroupBox());
			this->bEventEnd = (gcnew System::Windows::Forms::Button());
			this->bEventStart = (gcnew System::Windows::Forms::Button());
			this->isHevent = (gcnew System::Windows::Forms::CheckBox());
			this->isBevent = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->vItemDrop = (gcnew System::Windows::Forms::NumericUpDown());
			this->vExperience = (gcnew System::Windows::Forms::NumericUpDown());
			this->vMonthPrice = (gcnew System::Windows::Forms::NumericUpDown());
			this->isVIPSystem = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown9 = (gcnew System::Windows::Forms::NumericUpDown());
			this->userCredits = (gcnew System::Windows::Forms::NumericUpDown());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->userIsVIP = (gcnew System::Windows::Forms::CheckBox());
			this->userUpdate = (gcnew System::Windows::Forms::Button());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->userAccount = (gcnew System::Windows::Forms::TextBox());
			this->userSelect = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->WhisperMode = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vItemDrop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vExperience))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vMonthPrice))->BeginInit();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->userCredits))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->tabPage6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// hEvent
			// 
			this->hEvent->Location = System::Drawing::Point(0, 0);
			this->hEvent->Name = L"hEvent";
			this->hEvent->Size = System::Drawing::Size(200, 100);
			this->hEvent->TabIndex = 0;
			this->hEvent->TabStop = false;
			// 
			// hEventEnd
			// 
			this->hEventEnd->Location = System::Drawing::Point(0, 0);
			this->hEventEnd->Name = L"hEventEnd";
			this->hEventEnd->Size = System::Drawing::Size(75, 23);
			this->hEventEnd->TabIndex = 0;
			// 
			// hEventStart
			// 
			this->hEventStart->Location = System::Drawing::Point(0, 0);
			this->hEventStart->Name = L"hEventStart";
			this->hEventStart->Size = System::Drawing::Size(75, 23);
			this->hEventStart->TabIndex = 0;
			// 
			// bEvent
			// 
			this->bEvent->Location = System::Drawing::Point(0, 0);
			this->bEvent->Name = L"bEvent";
			this->bEvent->Size = System::Drawing::Size(200, 100);
			this->bEvent->TabIndex = 0;
			this->bEvent->TabStop = false;
			// 
			// bEventEnd
			// 
			this->bEventEnd->Location = System::Drawing::Point(0, 0);
			this->bEventEnd->Name = L"bEventEnd";
			this->bEventEnd->Size = System::Drawing::Size(75, 23);
			this->bEventEnd->TabIndex = 0;
			// 
			// bEventStart
			// 
			this->bEventStart->Location = System::Drawing::Point(0, 0);
			this->bEventStart->Name = L"bEventStart";
			this->bEventStart->Size = System::Drawing::Size(75, 23);
			this->bEventStart->TabIndex = 0;
			// 
			// isHevent
			// 
			this->isHevent->Location = System::Drawing::Point(0, 0);
			this->isHevent->Name = L"isHevent";
			this->isHevent->Size = System::Drawing::Size(104, 24);
			this->isHevent->TabIndex = 0;
			// 
			// isBevent
			// 
			this->isBevent->Location = System::Drawing::Point(0, 0);
			this->isBevent->Name = L"isBevent";
			this->isBevent->Size = System::Drawing::Size(104, 24);
			this->isBevent->TabIndex = 0;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->button8);
			this->groupBox7->Controls->Add(this->label48);
			this->groupBox7->Controls->Add(this->label47);
			this->groupBox7->Controls->Add(this->label46);
			this->groupBox7->Controls->Add(this->label45);
			this->groupBox7->Controls->Add(this->label44);
			this->groupBox7->Controls->Add(this->label42);
			this->groupBox7->Controls->Add(this->vItemDrop);
			this->groupBox7->Controls->Add(this->vExperience);
			this->groupBox7->Controls->Add(this->vMonthPrice);
			this->groupBox7->Controls->Add(this->isVIPSystem);
			this->groupBox7->Location = System::Drawing::Point(43, 126);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(346, 111);
			this->groupBox7->TabIndex = 3;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"VIP Settings";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(0, 0);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 0;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(230, 85);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(15, 13);
			this->label48->TabIndex = 10;
			this->label48->Text = L"%";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(92, 84);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(15, 13);
			this->label47->TabIndex = 10;
			this->label47->Text = L"%";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(146, 65);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(97, 13);
			this->label46->TabIndex = 9;
			this->label46->Text = L"VIP Drop Increase:";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(9, 65);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(88, 13);
			this->label45->TabIndex = 9;
			this->label45->Text = L"VIP XP Increase:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(191, 39);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(39, 13);
			this->label44->TabIndex = 8;
			this->label44->Text = L"Credits";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(9, 39);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(94, 13);
			this->label42->TabIndex = 7;
			this->label42->Text = L"VIP Monthly Price:";
			// 
			// vItemDrop
			// 
			this->vItemDrop->Location = System::Drawing::Point(149, 81);
			this->vItemDrop->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5000, 0, 0, 0});
			this->vItemDrop->Name = L"vItemDrop";
			this->vItemDrop->Size = System::Drawing::Size(81, 20);
			this->vItemDrop->TabIndex = 6;
			// 
			// vExperience
			// 
			this->vExperience->Location = System::Drawing::Point(10, 81);
			this->vExperience->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5000, 0, 0, 0});
			this->vExperience->Name = L"vExperience";
			this->vExperience->Size = System::Drawing::Size(81, 20);
			this->vExperience->TabIndex = 6;
			// 
			// vMonthPrice
			// 
			this->vMonthPrice->Location = System::Drawing::Point(104, 37);
			this->vMonthPrice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5000, 0, 0, 0});
			this->vMonthPrice->Name = L"vMonthPrice";
			this->vMonthPrice->Size = System::Drawing::Size(81, 20);
			this->vMonthPrice->TabIndex = 6;
			// 
			// isVIPSystem
			// 
			this->isVIPSystem->AutoSize = true;
			this->isVIPSystem->Location = System::Drawing::Point(12, 19);
			this->isVIPSystem->Name = L"isVIPSystem";
			this->isVIPSystem->Size = System::Drawing::Size(85, 17);
			this->isVIPSystem->TabIndex = 5;
			this->isVIPSystem->Text = L"Activate VIP";
			this->isVIPSystem->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label43);
			this->groupBox6->Controls->Add(this->numericUpDown9);
			this->groupBox6->Controls->Add(this->userCredits);
			this->groupBox6->Controls->Add(this->label40);
			this->groupBox6->Controls->Add(this->userIsVIP);
			this->groupBox6->Controls->Add(this->userUpdate);
			this->groupBox6->Controls->Add(this->label39);
			this->groupBox6->Controls->Add(this->userAccount);
			this->groupBox6->Controls->Add(this->userSelect);
			this->groupBox6->Location = System::Drawing::Point(6, 13);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(436, 107);
			this->groupBox6->TabIndex = 2;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Account GOLD/VIP Settings";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(336, 26);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(49, 13);
			this->label43->TabIndex = 8;
			this->label43->Text = L"expire in:";
			// 
			// numericUpDown9
			// 
			this->numericUpDown9->Location = System::Drawing::Point(318, 44);
			this->numericUpDown9->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999, 0, 0, 0});
			this->numericUpDown9->Name = L"numericUpDown9";
			this->numericUpDown9->Size = System::Drawing::Size(87, 20);
			this->numericUpDown9->TabIndex = 7;
			// 
			// userCredits
			// 
			this->userCredits->Location = System::Drawing::Point(196, 45);
			this->userCredits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999, 0, 0, 0});
			this->userCredits->Name = L"userCredits";
			this->userCredits->Size = System::Drawing::Size(87, 20);
			this->userCredits->TabIndex = 7;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(123, 47);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(67, 13);
			this->label40->TabIndex = 6;
			this->label40->Text = L"User Credits:";
			// 
			// userIsVIP
			// 
			this->userIsVIP->AutoSize = true;
			this->userIsVIP->Location = System::Drawing::Point(196, 25);
			this->userIsVIP->Name = L"userIsVIP";
			this->userIsVIP->Size = System::Drawing::Size(79, 17);
			this->userIsVIP->TabIndex = 5;
			this->userIsVIP->Text = L"Is User VIP";
			this->userIsVIP->UseVisualStyleBackColor = true;
			// 
			// userUpdate
			// 
			this->userUpdate->Location = System::Drawing::Point(256, 70);
			this->userUpdate->Name = L"userUpdate";
			this->userUpdate->Size = System::Drawing::Size(75, 23);
			this->userUpdate->TabIndex = 4;
			this->userUpdate->Text = L"Update User";
			this->userUpdate->UseVisualStyleBackColor = true;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(22, 26);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(75, 13);
			this->label39->TabIndex = 3;
			this->label39->Text = L"User Account:";
			// 
			// userAccount
			// 
			this->userAccount->Location = System::Drawing::Point(10, 44);
			this->userAccount->Name = L"userAccount";
			this->userAccount->Size = System::Drawing::Size(100, 20);
			this->userAccount->TabIndex = 2;
			// 
			// userSelect
			// 
			this->userSelect->Location = System::Drawing::Point(22, 70);
			this->userSelect->Name = L"userSelect";
			this->userSelect->Size = System::Drawing::Size(75, 23);
			this->userSelect->TabIndex = 1;
			this->userSelect->Text = L"Select User";
			this->userSelect->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(146, 153);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Apply Configs";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(191, 57);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(120, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"/post";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(191, 111);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 0;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(191, 84);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 20);
			this->numericUpDown4->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(95, 113);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Zen Cost to Post:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(95, 86);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(90, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Min Level to Use:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(95, 60);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Post Command:";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->groupBox4);
			this->tabPage5->Controls->Add(this->listBox1);
			this->tabPage5->Controls->Add(this->label29);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(434, 421);
			this->tabPage5->TabIndex = 0;
			this->tabPage5->Text = L"/post Command";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Controls->Add(this->textBox1);
			this->groupBox4->Controls->Add(this->numericUpDown1);
			this->groupBox4->Controls->Add(this->numericUpDown2);
			this->groupBox4->Controls->Add(this->label26);
			this->groupBox4->Controls->Add(this->label27);
			this->groupBox4->Controls->Add(this->label28);
			this->groupBox4->Location = System::Drawing::Point(3, 67);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(428, 182);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Post Command Configurations";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(154, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Apply Configs";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(199, 57);
			this->textBox1->MaxLength = 10;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"/post";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(199, 111);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 0;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(199, 84);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 0;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(103, 113);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(89, 13);
			this->label26->TabIndex = 1;
			this->label26->Text = L"Zen Cost to Post:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(103, 86);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(90, 13);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Min Level to Use:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(103, 60);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(81, 13);
			this->label28->TabIndex = 1;
			this->label28->Text = L"Post Command:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"On", L"Off"});
			this->listBox1->Location = System::Drawing::Point(215, 19);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(68, 30);
			this->listBox1->TabIndex = 2;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(125, 28);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(81, 13);
			this->label29->TabIndex = 1;
			this->label29->Text = L"Post Command:";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->groupBox5);
			this->tabPage6->Controls->Add(this->listBox2);
			this->tabPage6->Controls->Add(this->label38);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(434, 421);
			this->tabPage6->TabIndex = 1;
			this->tabPage6->Text = L"/add Commands";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button6);
			this->groupBox5->Controls->Add(this->textBox2);
			this->groupBox5->Controls->Add(this->textBox4);
			this->groupBox5->Controls->Add(this->textBox5);
			this->groupBox5->Controls->Add(this->textBox6);
			this->groupBox5->Controls->Add(this->textBox7);
			this->groupBox5->Controls->Add(this->numericUpDown5);
			this->groupBox5->Controls->Add(this->numericUpDown6);
			this->groupBox5->Controls->Add(this->numericUpDown7);
			this->groupBox5->Controls->Add(this->label30);
			this->groupBox5->Controls->Add(this->label31);
			this->groupBox5->Controls->Add(this->label32);
			this->groupBox5->Controls->Add(this->label33);
			this->groupBox5->Controls->Add(this->label34);
			this->groupBox5->Controls->Add(this->label35);
			this->groupBox5->Controls->Add(this->label36);
			this->groupBox5->Controls->Add(this->label37);
			this->groupBox5->Location = System::Drawing::Point(3, 67);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(428, 312);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Add Commands Configurations";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(157, 282);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(123, 23);
			this->button6->TabIndex = 3;
			this->button6->Text = L"Apply Configs";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(199, 176);
			this->textBox2->MaxLength = 10;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(120, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"/addcmd";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(199, 146);
			this->textBox4->MaxLength = 10;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(120, 20);
			this->textBox4->TabIndex = 2;
			this->textBox4->Text = L"/addene";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(199, 116);
			this->textBox5->MaxLength = 10;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(120, 20);
			this->textBox5->TabIndex = 2;
			this->textBox5->Text = L"/addvit";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(199, 86);
			this->textBox6->MaxLength = 10;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(120, 20);
			this->textBox6->TabIndex = 2;
			this->textBox6->Text = L"/addagi";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(199, 57);
			this->textBox7->MaxLength = 10;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(120, 20);
			this->textBox7->TabIndex = 2;
			this->textBox7->Text = L"/addstr";
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(199, 256);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32766, 0, 0, 0});
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(120, 20);
			this->numericUpDown5->TabIndex = 0;
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Location = System::Drawing::Point(199, 229);
			this->numericUpDown6->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, 0});
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(120, 20);
			this->numericUpDown6->TabIndex = 0;
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Location = System::Drawing::Point(199, 202);
			this->numericUpDown7->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999, 0, 0, 0});
			this->numericUpDown7->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(120, 20);
			this->numericUpDown7->TabIndex = 0;
			this->numericUpDown7->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(103, 258);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(84, 13);
			this->label30->TabIndex = 1;
			this->label30->Text = L"Max Points Add:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(103, 231);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(87, 13);
			this->label31->TabIndex = 1;
			this->label31->Text = L"Zen Cost to Add:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(103, 204);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(90, 13);
			this->label32->TabIndex = 1;
			this->label32->Text = L"Min Level to Use:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(103, 179);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(79, 13);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Add Command:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(103, 149);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(65, 13);
			this->label34->TabIndex = 1;
			this->label34->Text = L"Add Energy:";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(103, 119);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(62, 13);
			this->label35->TabIndex = 1;
			this->label35->Text = L"Add Vitality:";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(103, 89);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(59, 13);
			this->label36->TabIndex = 1;
			this->label36->Text = L"Add Agility:";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(103, 60);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(72, 13);
			this->label37->TabIndex = 1;
			this->label37->Text = L"Add Strength:";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"On", L"Off"});
			this->listBox2->Location = System::Drawing::Point(215, 19);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(68, 30);
			this->listBox2->TabIndex = 5;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(125, 28);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(84, 13);
			this->label38->TabIndex = 4;
			this->label38->Text = L"Add Commands:";
			// 
			// WhisperMode
			// 
			this->WhisperMode->Location = System::Drawing::Point(4, 22);
			this->WhisperMode->Margin = System::Windows::Forms::Padding(4);
			this->WhisperMode->Name = L"WhisperMode";
			this->WhisperMode->Padding = System::Windows::Forms::Padding(4);
			this->WhisperMode->Size = System::Drawing::Size(568, 384);
			this->WhisperMode->TabIndex = 0;
			this->WhisperMode->Text = L"Misc";
			this->WhisperMode->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->WhisperMode);
			this->tabControl1->Location = System::Drawing::Point(7, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(576, 410);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->richTextBox1);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(568, 384);
			this->tabPage4->TabIndex = 2;
			this->tabPage4->Text = L"Console";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ControlText;
			this->richTextBox1->ForeColor = System::Drawing::Color::Aqua;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(799, 496);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Window::richTextBox1_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Window::timer1_Tick);
			// 
			// Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(579, 412);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Window";
			this->Text = L"ACGroup WzAG.dll 5.0 Series";
			this->Load += gcnew System::EventHandler(this, &Window::Window_Load);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vItemDrop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vExperience))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vMonthPrice))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->userCredits))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
	private:System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
//			ConMemberReload("ConnectMember.txt");
//			configs.cmember.pasttime = 0;
//			LogAddFunc(3,"[Control Panel] ConnectMemberReload -> OK");
	}
	private: System::Void labelbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 talkprev->Text = "Preview: " + labelbox->Text + " " + textbox->Text;
			 }
	private: System::Void textbox_TextChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				 talkprev->Text = "Preview: " + labelbox->Text + " " + textbox->Text;
			 }
private: System::Void msgsend_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int x = 0; int y = 0; int z = 0;
			 if (pMode->Checked == true)
				x = 1;
			 if (atMode->Checked == true)
				y = 1;
	//		 if (wMode->Checked == true)
				 z = 1;

			 if (pMode->Checked == false && atMode->Checked == false) //&& wMode->Checked == false)
			 {
				 MessageBoxA("Select a Send Mode","[Control Panel] Notice");
				 return;
			 }

			 char* Label = (char*)(Marshal::StringToHGlobalAnsi(labelbox->Text + " ")).ToPointer();
			 char* Message = (char*)(Marshal::StringToHGlobalAnsi(textbox->Text)).ToPointer();
			 char* CharName = 0;
			 //g_Chat.ControlPanelTalk(x,y,z,CharName,Message,Label);
//			 LogAddFunc(2,"[Control Panel] Panel Talk Used");
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Configs();
		 }





private: System::Void dButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 int map, x, y, group, index, level, luck, exc, option, anct, skill;
			 map = Convert::ToInt16(dMap->Text);
			 x = Convert::ToInt16(dX->Text);
			 y = Convert::ToInt16(dY->Text);
			 index = Convert::ToInt16(dI->Text);
			 group = Convert::ToInt16(dG->Text);
			 level = Convert::ToInt16(dLv->Text);
			 option = Convert::ToInt16(dO->Text);
			 exc = Convert::ToInt16(dE->SelectedValue);

			 luck = 0; skill = 0; anct = 0;
			 
			 if(dLu->Checked == true)
				 luck = 1;
			 if(dS->Checked == true)
				 skill = 1;
			 if(dA->Checked == true)
				 anct = 5;

			ItemSerialCreateSend(6401, map,x,y,group * 512 + index,level,0,skill,luck,option,-1,exc,anct);

//			 LogAddFunc(2,"[Control Panel] Item Drop at %d %d %d",map,x,y);

		 }
			
private: System::Void Window_Load(System::Object^  sender, System::EventArgs^  e) {

			
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void wMode_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(NewWin.ChatMsg.DispChatMsg!="")
			 {
				  SYSTEMTIME t;
				  GetLocalTime(&t);
				  char currdate[11] = {0};
				  sprintf_s(currdate, "%02d:%02d:%02d ", t.wHour, t.wMinute, t.wSecond);

			 }
//			 Online();
//			 MaxUser();
//			 toolStripStatusLabel1->Text = "Online : " +NewWin.Main.OnlineAll+ " Maximum : "+NewWin.Main.MaxUsr+" GM's: "+NewWin.Main.OnlineGMS;
//			 toolStripProgressBar1->Value = NewWin.Main.OnlineAll;
//			 toolStripProgressBar1->Maximum = NewWin.Main.MaxUsr;

			 //Show Online users
//			 if(NewWin.Main.OnlineAll == 0)
//			 {
//			 label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(128)));
//			 label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(128)));
//			 panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(128)));
//			 panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(128)));
//			 }
//			 else
//			 {
//			 panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(120)));
//			 label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(120)));
//			 panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(120)));
//			 label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
//				static_cast<System::Int32>(static_cast<System::Byte>(120)));
//			 }
			 
			



	
			
		
		 }
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
