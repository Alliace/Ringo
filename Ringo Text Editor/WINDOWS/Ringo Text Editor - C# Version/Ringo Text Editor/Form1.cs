using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Ringo_Text_Editor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            openFileDialog1.FileName = null;
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog1.Title = "Open file in RTE";
            openFileDialog1.FileName = null;
            // выход, если была нажата кнопка Отмена и прочие (кроме ОК)
            if (openFileDialog1.ShowDialog() != DialogResult.OK) return;
            // всё. имя файла теперь хранится в openFileDialog1.FileName
            else
            {
                // create reader & open file
                StreamReader tr = new StreamReader(openFileDialog1.FileName);

                richTextBox1.Text = tr.ReadToEnd();
                this.Text = "RTE - " + openFileDialog1.FileName;

                // close the stream
                tr.Close();
            }
        }

        private void officialWebSiteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://alliace.unterblog.ru");
        }

        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            AboutBox1 ab = new AboutBox1();
            ab.Show();
        }

        private void closeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            this.Text = "Ringo Text Editor";
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string path = openFileDialog1.FileName;
            if (path == "")
            {
                if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    StreamWriter wr = new StreamWriter(saveFileDialog1.FileName);
                    wr.Write(richTextBox1.Text);
                    wr.Close();
                   
                }
            }
                else
                {
                    StreamWriter wr = new StreamWriter(openFileDialog1.FileName);
                    wr.Write(richTextBox1.Text);
                    wr.Close();

                }

            }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
               
                // Получение шрифта из диалогового окна.
               richTextBox1.SelectionFont =  fontDialog1.Font;
                
            }
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            richTextBox1.Undo();
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            richTextBox1.Redo();
        }

        private void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Undo();
        }

        private void redoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Redo();
        }
        }
    }
