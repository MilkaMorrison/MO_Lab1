#pragma once

#include <cmath>
#include <string>
#include <sstream>

namespace Lab1_visual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			coefficients = gcnew System::Collections::Generic::List<float>();
			
			// Привязка обработчиков событий
			this->buttonMin->Click += gcnew System::EventHandler(this, &MyForm::buttonMin_Click);
			this->buttonMax->Click += gcnew System::EventHandler(this, &MyForm::buttonMax_Click);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Collections::Generic::List<float>^ coefficients;

	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::TextBox^ textBoxCoefficients;


	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RadioButton^ radioButtonFibonacci;

	private: System::Windows::Forms::RadioButton^ radioButtonGolden;

	private: System::Windows::Forms::RadioButton^ radioButtonBisection;
	private: System::Windows::Forms::Button^ buttonMax;


	private: System::Windows::Forms::Button^ buttonMin;

	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::TextBox^ textBoxB;


	private: System::Windows::Forms::TextBox^ textBoxEpsilon;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxFMin;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxMaxX;

	private: System::Windows::Forms::TextBox^ textBoxMinX;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TextBox^ textBoxL;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxDegree;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBoxFMax;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxDegree = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCoefficients = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxL = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->buttonMax = (gcnew System::Windows::Forms::Button());
			this->buttonMin = (gcnew System::Windows::Forms::Button());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEpsilon = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButtonFibonacci = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonGolden = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonBisection = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxFMax = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxFMin = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxMaxX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMinX = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBoxDegree);
			this->groupBox1->Controls->Add(this->textBoxCoefficients);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(497, 98);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод данных";
			// 
			// textBoxDegree
			// 
			this->textBoxDegree->Location = System::Drawing::Point(159, 24);
			this->textBoxDegree->Name = L"textBoxDegree";
			this->textBoxDegree->Size = System::Drawing::Size(76, 22);
			this->textBoxDegree->TabIndex = 5;
			// 
			// textBoxCoefficients
			// 
			this->textBoxCoefficients->Location = System::Drawing::Point(284, 54);
			this->textBoxCoefficients->Name = L"textBoxCoefficients";
			this->textBoxCoefficients->Size = System::Drawing::Size(150, 22);
			this->textBoxCoefficients->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(272, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Коэффициенты (вводите через пробел):";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Степень многочлена:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->groupBox3);
			this->groupBox2->Controls->Add(this->radioButtonFibonacci);
			this->groupBox2->Controls->Add(this->radioButtonGolden);
			this->groupBox2->Controls->Add(this->radioButtonBisection);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 116);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(497, 208);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Методы";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBoxL);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->buttonMax);
			this->groupBox3->Controls->Add(this->buttonMin);
			this->groupBox3->Controls->Add(this->textBoxA);
			this->groupBox3->Controls->Add(this->textBoxB);
			this->groupBox3->Controls->Add(this->textBoxEpsilon);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Location = System::Drawing::Point(236, 13);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(255, 189);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Параметры метода";
			// 
			// textBoxL
			// 
			this->textBoxL->Location = System::Drawing::Point(171, 73);
			this->textBoxL->Name = L"textBoxL";
			this->textBoxL->Size = System::Drawing::Size(43, 22);
			this->textBoxL->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(17, 76);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(138, 16);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Допустимая длина l:";
			// 
			// buttonMax
			// 
			this->buttonMax->Location = System::Drawing::Point(20, 142);
			this->buttonMax->Name = L"buttonMax";
			this->buttonMax->Size = System::Drawing::Size(129, 23);
			this->buttonMax->TabIndex = 6;
			this->buttonMax->Text = L"Найти максимум";
			this->buttonMax->UseVisualStyleBackColor = true;
			this->buttonMax->Click += gcnew System::EventHandler(this, &MyForm::buttonMax_Click);
			// 
			// buttonMin
			// 
			this->buttonMin->Location = System::Drawing::Point(20, 113);
			this->buttonMin->Name = L"buttonMin";
			this->buttonMin->Size = System::Drawing::Size(129, 23);
			this->buttonMin->TabIndex = 5;
			this->buttonMin->Text = L"Найти минимум";
			this->buttonMin->UseVisualStyleBackColor = true;
			this->buttonMin->Click += gcnew System::EventHandler(this, &MyForm::buttonMin_Click);
			// 
			// textBoxA
			// 
			this->textBoxA->Location = System::Drawing::Point(122, 24);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(43, 22);
			this->textBoxA->TabIndex = 4;
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(171, 23);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(43, 22);
			this->textBoxB->TabIndex = 3;
			// 
			// textBoxEpsilon
			// 
			this->textBoxEpsilon->Location = System::Drawing::Point(171, 48);
			this->textBoxEpsilon->Name = L"textBoxEpsilon";
			this->textBoxEpsilon->Size = System::Drawing::Size(43, 22);
			this->textBoxEpsilon->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 16);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Границы [a, b]:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Точность epsilon:";
			// 
			// radioButtonFibonacci
			// 
			this->radioButtonFibonacci->AutoSize = true;
			this->radioButtonFibonacci->Location = System::Drawing::Point(9, 65);
			this->radioButtonFibonacci->Name = L"radioButtonFibonacci";
			this->radioButtonFibonacci->Size = System::Drawing::Size(187, 20);
			this->radioButtonFibonacci->TabIndex = 2;
			this->radioButtonFibonacci->TabStop = true;
			this->radioButtonFibonacci->Text = L"Метод чисел Фибоначчи";
			this->radioButtonFibonacci->UseVisualStyleBackColor = true;
			// 
			// radioButtonGolden
			// 
			this->radioButtonGolden->AutoSize = true;
			this->radioButtonGolden->Location = System::Drawing::Point(9, 42);
			this->radioButtonGolden->Name = L"radioButtonGolden";
			this->radioButtonGolden->Size = System::Drawing::Size(198, 20);
			this->radioButtonGolden->TabIndex = 1;
			this->radioButtonGolden->TabStop = true;
			this->radioButtonGolden->Text = L"Метод \"золотого\" сечения";
			this->radioButtonGolden->UseVisualStyleBackColor = true;
			// 
			// radioButtonBisection
			// 
			this->radioButtonBisection->AutoSize = true;
			this->radioButtonBisection->Location = System::Drawing::Point(9, 19);
			this->radioButtonBisection->Name = L"radioButtonBisection";
			this->radioButtonBisection->Size = System::Drawing::Size(214, 20);
			this->radioButtonBisection->TabIndex = 0;
			this->radioButtonBisection->TabStop = true;
			this->radioButtonBisection->Text = L"Метод половинного деления";
			this->radioButtonBisection->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBoxFMax);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->textBoxFMin);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->textBoxMaxX);
			this->groupBox4->Controls->Add(this->textBoxMinX);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox4->Location = System::Drawing::Point(12, 330);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(497, 167);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Результаты";
			// 
			// textBoxFMax
			// 
			this->textBoxFMax->Location = System::Drawing::Point(244, 121);
			this->textBoxFMax->Name = L"textBoxFMax";
			this->textBoxFMax->Size = System::Drawing::Size(100, 22);
			this->textBoxFMax->TabIndex = 7;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 124);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(236, 16);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Значение функции f(x) в точке max:";
			// 
			// textBoxFMin
			// 
			this->textBoxFMin->Location = System::Drawing::Point(244, 54);
			this->textBoxFMin->Name = L"textBoxFMin";
			this->textBoxFMin->Size = System::Drawing::Size(100, 22);
			this->textBoxFMin->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 57);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(232, 16);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Значение функции f(x) в точке min:";
			// 
			// textBoxMaxX
			// 
			this->textBoxMaxX->Location = System::Drawing::Point(168, 94);
			this->textBoxMaxX->Name = L"textBoxMaxX";
			this->textBoxMaxX->Size = System::Drawing::Size(100, 22);
			this->textBoxMaxX->TabIndex = 3;
			// 
			// textBoxMinX
			// 
			this->textBoxMinX->Location = System::Drawing::Point(168, 27);
			this->textBoxMinX->Name = L"textBoxMinX";
			this->textBoxMinX->Size = System::Drawing::Size(100, 22);
			this->textBoxMinX->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(135, 16);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Точка максимума x:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(129, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Точка минимума x:";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(515, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(465, 491);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 509);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
		float CalculateFunction(float x) {
			float res = 0;
			int length = coefficients->Count;
			for (int i = 0; i < length; i++) {
				res += coefficients[i] * pow(x, length - 1 - i);
			}
			return res;
		}

		float BisectionMethod(float a, float b, float epsilon, bool find_max) {
			int k = 0;
			float x = (a + b) / 2.0f;
			float L = fabs(b - a);

			while (L > epsilon){
				float y = a + L / 4.0f;
				float z = b - L / 4.0f;

				float func_x = CalculateFunction(x);
				float func_y = CalculateFunction(y);
				float func_z = CalculateFunction(z);

				if ((!find_max && func_y < func_x) || (find_max && func_y > func_x)) {
					b = x;
					x = y;
				}
				else {
					if ((!find_max && func_z < func_x) || (find_max && func_z > func_x)) {
						a = x;
						x = z;
					}
					else {
						a = y;
						b = z;
					}
				}
				L = fabs(b - a);
				k++;
			}
			return x;
		}

		float GoldenSectionMethod(float a, float b, float epsilon, bool find_max) {
			int k = 0;
			float del = fabs(a - b);
			float y = a + (3.0f - sqrt(5.0f)) / 2.0f * (b - a);
			float z = a + b - y;

			while (del > epsilon) {
				float func_y = CalculateFunction(y);
				float func_z = CalculateFunction(z);

				if ((!find_max && func_y <= func_z) || (find_max && func_y >= func_z)) {
					b = z;
					z = y;
					y = a + b - y;
				}
				else {
					a = y;
					y = z;
					z = a + b - z;
				}
				del = fabs(a - b);
				k++;
			}
			float x = (a + b) / 2.0f;
			return x;
		}

		float FibonacciNumber(int N) {
			if (N < 0) return 0;
			if (N == 0 || N == 1) return 1;

			float a = 1, b = 1;
			for (int i = 2; i <= N; ++i) {
				float next = a + b;
				a = b;
				b = next;
			}
			return b;
		}

		float FibonacciMethod(float a, float b, float epsilon, float l, bool find_max) {
			float FN = fabs(a - b) / l;
			int N = 0;
			while (FibonacciNumber(N) < FN) {
				N++;
				if (N > 1000) {
					printf("Слишком большое N, возможно переполнение");
					return 0;
				}
			}

			int k = 0;
			float y = a + (FibonacciNumber(N - 2) / FibonacciNumber(N)) * (b - a);
			float z = a + (FibonacciNumber(N - 1) / FibonacciNumber(N)) * (b - a);

			while (k < N - 2) {
				float func_y = CalculateFunction(y);
				float func_z = CalculateFunction(z);

				if ((!find_max && func_y <= func_z) || (find_max && func_y >= func_z)) {
					b = z;
					z = y;
					y = a + (FibonacciNumber(N - k - 3) / FibonacciNumber(N - k - 1)) * (b - a);
				}
				else {
					a = y;
					y = z;
					z = a + (FibonacciNumber(N - k - 2) / FibonacciNumber(N - k - 1)) * (b - a);
				}
				k++;
			}
			float y_final = y;
			float z_final = y_final + epsilon;
			float func_y_final = CalculateFunction(y_final);
			float func_z_final = CalculateFunction(z_final);

			if (func_y_final <= func_z_final) {
				b = z_final;
			}
			else {
				a = y_final;
			}
			float x = (a + b) / 2.0f;
			return x;
		}

	private: void DrawFunctionGraph(float a, float b) {
		chart1->Series["Series1"]->Points->Clear();

		chart1->Series["Series1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		chart1->Series["Series1"]->Color = System::Drawing::Color::Blue;
		chart1->Series["Series1"]->BorderWidth = 2;

		chart1->ChartAreas["ChartArea1"]->AxisX->Title = "x";
		chart1->ChartAreas["ChartArea1"]->AxisY->Title = "f(x)";

		chart1->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Format = "F2";

		//  интервал для оси X
		chart1->ChartAreas["ChartArea1"]->AxisX->IntervalAutoMode =
			System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;

		float step = (b - a) / 100.0f;

		for (float x = a; x <= b; x += step) {
			float y = CalculateFunction(x);
			chart1->Series["Series1"]->Points->AddXY(x, y);
		}
		chart1->Update();
	}

	private: System::Void buttonMin_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			coefficients->Clear();

			if (String::IsNullOrWhiteSpace(textBoxDegree->Text)) {
				MessageBox::Show("Введите степень многочлена!", "Ошибка");
				return;
			}
			if (String::IsNullOrWhiteSpace(textBoxCoefficients->Text)) {
				MessageBox::Show("Введите коэффициенты функции!", "Ошибка");
				return;
			}

			int degree = System::Convert::ToInt32(textBoxDegree->Text);
			array<String^>^ coefs = textBoxCoefficients->Text->Split(' ');
			for each (String ^ coef in coefs) {
				if (!String::IsNullOrWhiteSpace(coef)) {
					coefficients->Add(System::Convert::ToSingle(coef));
				}
			}

			if (coefficients->Count != degree + 1) {
				MessageBox::Show("Количество коэффициентов не соответствует степени многочлена!", "Ошибка");
				return;
			}

			float a = System::Convert::ToSingle(textBoxA->Text);
			float b = System::Convert::ToSingle(textBoxB->Text);
			DrawFunctionGraph(a, b);

			float epsilon = System::Convert::ToSingle(textBoxEpsilon->Text);
			float resultX = 0;

			if (radioButtonBisection->Checked) {
				resultX = BisectionMethod(a, b, epsilon, false);
			}
			else if (radioButtonGolden->Checked) {
				resultX = GoldenSectionMethod(a, b, epsilon, false);
			}
			else if (radioButtonFibonacci->Checked) {
				float l = System::Convert::ToSingle(textBoxL->Text);
				resultX = FibonacciMethod(a, b, epsilon, l, false);
			}

			float resultFMin = CalculateFunction(resultX);
			textBoxMinX->Text = resultX.ToString("F6");
			textBoxFMin->Text = resultFMin.ToString("F6");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void buttonMax_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			coefficients->Clear();

			if (String::IsNullOrWhiteSpace(textBoxDegree->Text)) {
				MessageBox::Show("Введите степень многочлена!", "Ошибка");
				return;
			}
			if (String::IsNullOrWhiteSpace(textBoxCoefficients->Text)) {
				MessageBox::Show("Введите коэффициенты функции!", "Ошибка");
				return;
			}

			int degree = System::Convert::ToInt32(textBoxDegree->Text);
			array<String^>^ coefs = textBoxCoefficients->Text->Split(' ');
			for each (String ^ coef in coefs) {
				if (!String::IsNullOrWhiteSpace(coef)) {
					coefficients->Add(System::Convert::ToSingle(coef));
				}
			}

			if (coefficients->Count != degree + 1) {
				MessageBox::Show("Количество коэффициентов не соответствует степени многочлена!", "Ошибка");
				return;
			}

			float a = System::Convert::ToSingle(textBoxA->Text);
			float b = System::Convert::ToSingle(textBoxB->Text);
			DrawFunctionGraph(a, b);

			float epsilon = System::Convert::ToSingle(textBoxEpsilon->Text);
			float resultX = 0;

			if (radioButtonBisection->Checked) {
				resultX = BisectionMethod(a, b, epsilon, true);
			}
			else if (radioButtonGolden->Checked) {
				resultX = GoldenSectionMethod(a, b, epsilon, true);
			}
			else if (radioButtonFibonacci->Checked) {
				float l = System::Convert::ToSingle(textBoxL->Text);
				resultX = FibonacciMethod(a, b, epsilon, l, true);
			}

			float resultFMax = CalculateFunction(resultX);
			textBoxMaxX->Text = resultX.ToString("F6");
			textBoxFMax->Text = resultFMax.ToString("F6");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
