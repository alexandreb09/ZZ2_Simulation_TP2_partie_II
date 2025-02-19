#pragma once

#ifndef FORM_MAIN
#define FORM_MAIN

#include "simulation.h"

namespace Simulation_file {
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Description r�sum�e de form_main
	/// </summary>
	public ref class form_main : public System::Windows::Forms::Form
	{
	public:
		form_main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~form_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TextBox^  textBox4;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;




	protected:

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form_main::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->Location = System::Drawing::Point(677, 290);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(346, 54);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Simuler";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &form_main::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(891, 56);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &form_main::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(714, 106);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Dur�e entre 2 clients";
			this->label1->Click += gcnew System::EventHandler(this, &form_main::label1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 391);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(516, 281);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(705, 59);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Dur�e de la simulation";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(891, 103);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(671, 150);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(184, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Dur�e traitement machine A";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(891, 147);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(132, 22);
			this->textBox3->TabIndex = 9;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Tan;
			this->chart1->BorderlineColor = System::Drawing::Color::Black;
			this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			this->chart1->BorderlineWidth = 2;
			chartArea3->BackImageTransparentColor = System::Drawing::Color::Silver;
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			this->chart1->Cursor = System::Windows::Forms::Cursors::Arrow;
			legend3->Alignment = System::Drawing::StringAlignment::Center;
			legend3->BackColor = System::Drawing::Color::Transparent;
			legend3->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(546, 363);
			this->chart1->Margin = System::Windows::Forms::Padding(4);
			this->chart1->Name = L"chart1";
			series3->BackSecondaryColor = System::Drawing::Color::Maroon;
			series3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->Legend = L"Legend1";
			series3->Name = L"Temps moyen dans le syst�me (Ma + MB + MC)";
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(630, 369);
			this->chart1->TabIndex = 11;
			this->chart1->Text = L"Temps moyen dans syst�me";
			title3->BackColor = System::Drawing::Color::Gainsboro;
			title3->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::Center;
			title3->Name = L"Title1";
			title3->ShadowColor = System::Drawing::Color::White;
			title3->Text = L"Temps moyen dans la systeme (MA + MB + MC)";
			this->chart1->Titles->Add(title3);
			this->chart1->Click += gcnew System::EventHandler(this, &form_main::chart1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(891, 197);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(132, 22);
			this->textBox4->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(671, 200);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(184, 17);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Dur�e traitement machine B";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 128);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(450, 110);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &form_main::pictureBox1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(670, 247);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(184, 17);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Dur�e traitement machine C";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(891, 247);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(132, 22);
			this->textBox5->TabIndex = 17;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 290);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 55);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Aide erreur type";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &form_main::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(97, 47);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(253, 32);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Simulation serveurs";
			this->label6->Click += gcnew System::EventHandler(this, &form_main::label6_Click);
			// 
			// form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Tan;
			this->ClientSize = System::Drawing::Size(1208, 762);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"form_main";
			this->Text = L"form_main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->richTextBox1->Clear();
			this->chart1->Series[0]->Points->Clear();

			System::String^ chaineBTN1 = this->textBox1->Text;
			System::String^ chaineBTN2 = this->textBox2->Text;
			System::String^ chaineBTN3 = this->textBox3->Text;
			System::String^ chaineBTN4 = this->textBox4->Text;
			System::String^ chaineBTN5 = this->textBox5->Text;

			if (chaineBTN1 != "" && chaineBTN2 != "" && chaineBTN3!="" && chaineBTN4 !="" && chaineBTN5 != "") {
				int duree_sim = System::Convert::ToInt32(chaineBTN1);
				double duree_entre_2_cl = System::Convert::ToDouble(chaineBTN2);
				double duree_traitement_cl_m1 = System::Convert::ToDouble(chaineBTN3);
				double duree_traitement_cl_m2 = System::Convert::ToDouble(chaineBTN4);
				double duree_traitement_cl_m3 = System::Convert::ToDouble(chaineBTN5);

				simuler(duree_sim, duree_entre_2_cl, duree_traitement_cl_m1, duree_traitement_cl_m2, duree_traitement_cl_m3, richTextBox1, chart1);
			}
		}
		private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox1->Clear();
		std::ostringstream oss;
		oss << "Si erreur de type lev�e :\n\n    - Penser � mettre une \",\" (VIRGULE) pour les nombres r�els (et pas un \".\" POINT) ";
		oss << "\n\nLes types actuels sont :\n    - Dur�e simulation : ENTIER\n    - Dur�e entre deux clients : FLOAT";
		oss << "\n    - Dur�e traitement machine i : FLOAT";
		std::string ch = oss.str();
		System::String^ result = gcnew System::String(ch.c_str());
		richTextBox1->AppendText(result);
	}
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

#endif
