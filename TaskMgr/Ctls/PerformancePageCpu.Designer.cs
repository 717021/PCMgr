﻿namespace PCMgr.Ctls
{
    partial class PerformancePageCpu
    {
        /// <summary> 
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region 组件设计器生成的代码

        /// <summary> 
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PerformancePageCpu));
            this.performanceInfos = new PCMgr.Ctls.PerformanceInfos();
            this.performanceGridGlobal = new PCMgr.Ctls.PerformanceGrid();
            this.performanceTitle = new PCMgr.Ctls.PerformanceTitle();
            this.performanceCpus = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.performanceCpus)).BeginInit();
            this.SuspendLayout();
            // 
            // performanceInfos
            // 
            resources.ApplyResources(this.performanceInfos, "performanceInfos");
            this.performanceInfos.ColorText = System.Drawing.Color.Black;
            this.performanceInfos.ColorTitle = System.Drawing.Color.Gray;
            this.performanceInfos.FontText = new System.Drawing.Font("微软雅黑", 9F);
            this.performanceInfos.FontTextSpeical = new System.Drawing.Font("微软雅黑", 15F);
            this.performanceInfos.FontTitle = new System.Drawing.Font("微软雅黑", 9F);
            this.performanceInfos.ItemMargan = 0;
            this.performanceInfos.LineOffest = 0;
            this.performanceInfos.MaxSpeicalItemsWidth = 250;
            this.performanceInfos.Name = "performanceInfos";
            // 
            // performanceGridGlobal
            // 
            resources.ApplyResources(this.performanceGridGlobal, "performanceGridGlobal");
            this.performanceGridGlobal.BgColor = System.Drawing.Color.FromArgb(((int)(((byte)(241)))), ((int)(((byte)(246)))), ((int)(((byte)(250)))));
            this.performanceGridGlobal.BottomTextHeight = 20;
            this.performanceGridGlobal.DrawColor = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(125)))), ((int)(((byte)(187)))));
            this.performanceGridGlobal.DrawColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(125)))), ((int)(((byte)(187)))));
            this.performanceGridGlobal.DrawData2 = false;
            this.performanceGridGlobal.DrawData2Bg = false;
            this.performanceGridGlobal.GridColor = System.Drawing.Color.FromArgb(((int)(((byte)(206)))), ((int)(((byte)(226)))), ((int)(((byte)(240)))));
            this.performanceGridGlobal.LeftBottomText = "60 秒";
            this.performanceGridGlobal.LeftText = "% Useage";
            this.performanceGridGlobal.Name = "performanceGridGlobal";
            this.performanceGridGlobal.RightBottomText = "0";
            this.performanceGridGlobal.RightText = "100 %";
            this.performanceGridGlobal.TopTextHeight = 20;
            // 
            // performanceTitle
            // 
            resources.ApplyResources(this.performanceTitle, "performanceTitle");
            this.performanceTitle.Name = "performanceTitle";
            this.performanceTitle.SmallTitle = "cpu id and name";
            this.performanceTitle.SmallTitleFont = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.performanceTitle.Title = "CPU";
            this.performanceTitle.TitleFont = new System.Drawing.Font("微软雅黑", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            // 
            // performanceCpus
            // 
            resources.ApplyResources(this.performanceCpus, "performanceCpus");
            this.performanceCpus.Name = "performanceCpus";
            this.performanceCpus.TabStop = false;
            this.performanceCpus.Paint += new System.Windows.Forms.PaintEventHandler(this.performanceCpus_Paint);
            // 
            // PerformancePageCpu
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.Controls.Add(this.performanceCpus);
            this.Controls.Add(this.performanceInfos);
            this.Controls.Add(this.performanceGridGlobal);
            this.Controls.Add(this.performanceTitle);
            this.Name = "PerformancePageCpu";
            this.Load += new System.EventHandler(this.PerformanceCpu_Load);
            ((System.ComponentModel.ISupportInitialize)(this.performanceCpus)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        public PerformanceGrid performanceGridGlobal;
        public PerformanceTitle performanceTitle;
        public PerformanceInfos performanceInfos;
        private System.Windows.Forms.PictureBox performanceCpus;
    }
}
