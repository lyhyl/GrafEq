using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

// This is the code for your desktop app.
// Press Ctrl+F5 (or go to Debug > Start Without Debugging) to run your app.

namespace keygenCS
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = ACFXGetCodeBySecert(ACFXGetSecertByName(textBox1.Text.ToUpper()));
        }
        private byte[] ACFXGetSecertByName(string name)
        {
            byte[] secert = new byte[11];
            byte[] vResult = new byte[5];
            vResult[0] = secert[0] = 0; // rand();
            vResult[1] = secert[1] = 0; // rand();
            vResult[2] = secert[4] = 0; // rand();
            vResult[3] = secert[6] = 0; // rand();
            vResult[4] = secert[7] = 0; // rand();

            for (int i = 0; i < 5; i++)
            {
                int v16 = ACDXSecretCode1[i];
                for (int j = 0; j < name.Length; j++)
                {
                    v16 += name[j] | (17 * i + vResult[(i + j) % 5]);
                }
                secert[ACDXSecretCode2[i]] = (byte)v16;
            }
            return secert;
        }

        private string ACFXGetCodeBySecert(byte[] secert)
        {
            StringBuilder code = new StringBuilder();
            byte[] xcode = new byte[16];

            for (int i = 0; i < 16; i++)
            {
                int bb = i * 5;
                int c = bb / 8;
                int cr = bb % 8;
                code.Append((char)ACDXSecertCode0[((secert[c] >> cr) | (secert[c + 1] << (8 - cr))) & 0b11111]);
            }
            return code.ToString();
        }

        private byte[] ACDXSecertCode0 = new byte[] {
            0x59,	//'Y'
	        0x35,	//'5'
	        0x45,	//'E'
	        0x37,	//'7'
	        0x55,	//'U'
	        0x5A,	//'Z'
	        0x39,	//'9'
	        0x58,	//'X'
	        0x50,	//'P'
	        0x32,	//'2'
	        0x33,	//'3'
	        0x51,	//'Q'
	        0x57,	//'W'
	        0x4B,	//'K'
	        0x4D,	//'M'
	        0x4E,	//'N'
	        0x36,	//'6'
	        0x41,	//'A'
	        0x2B,	//'+'
	        0x54,	//'T'
	        0x53,	//'S'
	        0x43,	//'C'
	        0x21,	//'!'
	        0x34,	//'4'
	        0x56,	//'V'
	        0x46,	//'F'
	        0x47,	//'G'
	        0x48,	//'H'
	        0x4A,	//'J'
	        0x52,	//'R'
	        0x2D,	//'-'
	        0x44	//'D'
        };

        private byte[] ACDXSecretCode1 = new byte[]{ // 5 elements enough
	        0x5D,
            0x22,
            0x4F,
            0x4E,
            0xFC
        };

        private byte[] ACDXSecretCode2 = new byte[]{ // 5 elements enough
	        2,
            3,
            5,
            8,
            9
        };
    }
}
