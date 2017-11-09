using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;

namespace WinConsoleMonitor
{
    public partial class Form1 : Form
    {
        public SerialPort sp;
        Thread th_listen = null;

        delegate void SetTextCallback(String txt, Color c);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox1.Items.AddRange(SerialPort.GetPortNames());
            if (listBox1.Items.IndexOf("COM3") > -1)
                listBox1.SelectedIndex = listBox1.Items.IndexOf("COM3");
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (th_listen != null)
                th_listen.Abort();

            sp = new SerialPort(listBox1.Text, 9600);
            sp.Encoding = Encoding.UTF8;
            sp.Open();
            richTextBox1.AppendText("Open " + listBox1.Text + "(9600)" + Environment.NewLine, Color.Blue);
            th_listen = new Thread(readThread);
            th_listen.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.AppendText(DateTime.Now.ToString("H:mm:ss.ffff") + " => " + textBox1.Text + Environment.NewLine,Color.Red);
            sp.WriteLine(textBox1.Text);
        }

        void readThread()
        {
            while(true)
            {
                var s = sp.ReadLine();
                SetTextCallback d = new SetTextCallback(SetText);
                this.Invoke(d, new object[] { DateTime.Now.ToString("H:mm:ss.ffff") + " <= " + s , Color.Green });
                
            }
        }

        void SetText(string txt, Color c)
        {
            richTextBox1.AppendText(txt , c);
        }

        private void textBox1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Enter)
                button1_Click(this, null);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            th_listen.Abort();
        }
    }
}
