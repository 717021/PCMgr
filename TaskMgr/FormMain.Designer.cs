﻿namespace PCMgr
{
    partial class FormMain
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

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.splitContainerPerfCtls = new System.Windows.Forms.SplitContainer();
            this.sp3 = new System.Windows.Forms.Panel();
            this.performanceLeftList = new PCMgr.Ctls.PerformanceList();
            this.splitContainerFm = new System.Windows.Forms.SplitContainer();
            this.treeFmLeft = new System.Windows.Forms.TreeView();
            this.imageListFileMgrLeft = new System.Windows.Forms.ImageList(this.components);
            this.listFm = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.imageListFileTypeList = new System.Windows.Forms.ImageList(this.components);
            this.tabControlMain = new System.Windows.Forms.TabControl();
            this.tabPageProcCtl = new System.Windows.Forms.TabPage();
            this.sp4 = new System.Windows.Forms.PictureBox();
            this.btnEndProcess = new System.Windows.Forms.Button();
            this.listProcess = new PCMgr.Ctls.TaskMgrList();
            this.lbProcessCount = new System.Windows.Forms.Label();
            this.expandFewerDetals = new PCMgr.Aero.ExpandButton();
            this.tabPageKernelCtl = new System.Windows.Forms.TabPage();
            this.pl_driverNotLoadTip = new System.Windows.Forms.Panel();
            this.linkRestartAsAdminDriver = new System.Windows.Forms.LinkLabel();
            this.lbRestartAsAdminDriver = new System.Windows.Forms.Label();
            this.sp5 = new System.Windows.Forms.PictureBox();
            this.linkLabelShowKernelTools = new System.Windows.Forms.LinkLabel();
            this.lbDriversCount = new System.Windows.Forms.Label();
            this.listDrivers = new System.Windows.Forms.ListView();
            this.columnHeader15 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader16 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader17 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader18 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader19 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader20 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader22 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader23 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabPagePerfCtl = new System.Windows.Forms.TabPage();
            this.linkLabelOpenPerfMon = new System.Windows.Forms.LinkLabel();
            this.tabPageUWPCtl = new System.Windows.Forms.TabPage();
            this.pl_UWPEnumFailTip = new System.Windows.Forms.Panel();
            this.lbUWPEnumFailText = new System.Windows.Forms.Label();
            this.listUwpApps = new PCMgr.Ctls.TaskMgrList();
            this.tabPageUsers = new System.Windows.Forms.TabPage();
            this.listUsers = new PCMgr.Ctls.TaskMgrList();
            this.tabPageScCtl = new System.Windows.Forms.TabPage();
            this.pl_ScNeedAdminTip = new System.Windows.Forms.Panel();
            this.linkRebootAsAdmin = new System.Windows.Forms.LinkLabel();
            this.lbScNeedAdminTip = new System.Windows.Forms.Label();
            this.sp2 = new System.Windows.Forms.PictureBox();
            this.linkOpenScMsc = new System.Windows.Forms.LinkLabel();
            this.listService = new System.Windows.Forms.ListView();
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader11 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader12 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader13 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader14 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader21 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lbServicesCount = new System.Windows.Forms.Label();
            this.tabPageDetals = new System.Windows.Forms.TabPage();
            this.btnEndProcessDetals = new System.Windows.Forms.Button();
            this.listProcessDetals = new System.Windows.Forms.ListView();
            this.imageListProcessDetalsIcons = new System.Windows.Forms.ImageList(this.components);
            this.tabPageStartCtl = new System.Windows.Forms.TabPage();
            this.pl_bios_time = new System.Windows.Forms.Panel();
            this.lbBiosTime = new System.Windows.Forms.Label();
            this.lbBiosTimeText = new System.Windows.Forms.Label();
            this.listStartup = new PCMgr.Ctls.TaskMgrList();
            this.tabPageFileCtl = new System.Windows.Forms.TabPage();
            this.lbFileMgrStatus = new System.Windows.Forms.Label();
            this.btnFmAddGoto = new System.Windows.Forms.Button();
            this.textBoxFmCurrent = new System.Windows.Forms.TextBox();
            this.lbStartingStatus = new System.Windows.Forms.Label();
            this.spBottom = new System.Windows.Forms.PictureBox();
            this.toolTip = new System.Windows.Forms.ToolTip(this.components);
            this.contextMenuStripUWP = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.打开应用ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.卸载应用ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.打开安装位置ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.复制名称ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.复制完整名称ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.复制发布者ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.listApps = new PCMgr.Ctls.TaskMgrList();
            this.pl_simple = new System.Windows.Forms.Panel();
            this.expandMoreDetals = new PCMgr.Aero.ExpandButton();
            this.btnEndTaskSimple = new System.Windows.Forms.Button();
            this.contextMenuStripProcDetalsCol = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.隐藏列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.选择列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.将此列调整为合适大小ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStripTray = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.显示隐藏主界面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出程序ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pl_perfGridHost = new System.Windows.Forms.Panel();
            this.contextMenuStripMainHeader = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.资源值ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.内存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.百分比ToolStripMenuItemRam = new System.Windows.Forms.ToolStripMenuItem();
            this.值ToolStripMenuItemRam = new System.Windows.Forms.ToolStripMenuItem();
            this.磁盘ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.百分比ToolStripMenuItemDisk = new System.Windows.Forms.ToolStripMenuItem();
            this.值ToolStripMenuItemDisk = new System.Windows.Forms.ToolStripMenuItem();
            this.网络ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.百分比ToolStripMenuItemNet = new System.Windows.Forms.ToolStripMenuItem();
            this.值ToolStripMenuItemNet = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStripPerfListLeft = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.隐藏图形ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fileSystemWatcher = new System.IO.FileSystemWatcher();
            this.notifyIcon = new System.Windows.Forms.NotifyIcon(this.components);
            this.check_showAllProcess = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerPerfCtls)).BeginInit();
            this.splitContainerPerfCtls.Panel1.SuspendLayout();
            this.splitContainerPerfCtls.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerFm)).BeginInit();
            this.splitContainerFm.Panel1.SuspendLayout();
            this.splitContainerFm.Panel2.SuspendLayout();
            this.splitContainerFm.SuspendLayout();
            this.tabControlMain.SuspendLayout();
            this.tabPageProcCtl.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sp4)).BeginInit();
            this.tabPageKernelCtl.SuspendLayout();
            this.pl_driverNotLoadTip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sp5)).BeginInit();
            this.tabPagePerfCtl.SuspendLayout();
            this.tabPageUWPCtl.SuspendLayout();
            this.pl_UWPEnumFailTip.SuspendLayout();
            this.tabPageUsers.SuspendLayout();
            this.tabPageScCtl.SuspendLayout();
            this.pl_ScNeedAdminTip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sp2)).BeginInit();
            this.tabPageDetals.SuspendLayout();
            this.tabPageStartCtl.SuspendLayout();
            this.pl_bios_time.SuspendLayout();
            this.tabPageFileCtl.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spBottom)).BeginInit();
            this.contextMenuStripUWP.SuspendLayout();
            this.pl_simple.SuspendLayout();
            this.contextMenuStripProcDetalsCol.SuspendLayout();
            this.contextMenuStripTray.SuspendLayout();
            this.contextMenuStripMainHeader.SuspendLayout();
            this.contextMenuStripPerfListLeft.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher)).BeginInit();
            this.SuspendLayout();
            // 
            // splitContainerPerfCtls
            // 
            resources.ApplyResources(this.splitContainerPerfCtls, "splitContainerPerfCtls");
            this.splitContainerPerfCtls.Name = "splitContainerPerfCtls";
            // 
            // splitContainerPerfCtls.Panel1
            // 
            this.splitContainerPerfCtls.Panel1.Controls.Add(this.sp3);
            this.splitContainerPerfCtls.Panel1.Controls.Add(this.performanceLeftList);
            resources.ApplyResources(this.splitContainerPerfCtls.Panel1, "splitContainerPerfCtls.Panel1");
            // 
            // splitContainerPerfCtls.Panel2
            // 
            resources.ApplyResources(this.splitContainerPerfCtls.Panel2, "splitContainerPerfCtls.Panel2");
            // 
            // sp3
            // 
            this.sp3.BackColor = System.Drawing.Color.Silver;
            this.sp3.Cursor = System.Windows.Forms.Cursors.SizeWE;
            resources.ApplyResources(this.sp3, "sp3");
            this.sp3.Name = "sp3";
            // 
            // performanceLeftList
            // 
            this.performanceLeftList.BackColor = System.Drawing.Color.White;
            resources.ApplyResources(this.performanceLeftList, "performanceLeftList");
            this.performanceLeftList.DrawDataGrid = true;
            this.performanceLeftList.Name = "performanceLeftList";
            this.performanceLeftList.Selectedtem = null;
            // 
            // splitContainerFm
            // 
            resources.ApplyResources(this.splitContainerFm, "splitContainerFm");
            this.splitContainerFm.Name = "splitContainerFm";
            // 
            // splitContainerFm.Panel1
            // 
            this.splitContainerFm.Panel1.Controls.Add(this.treeFmLeft);
            resources.ApplyResources(this.splitContainerFm.Panel1, "splitContainerFm.Panel1");
            // 
            // splitContainerFm.Panel2
            // 
            this.splitContainerFm.Panel2.Controls.Add(this.listFm);
            resources.ApplyResources(this.splitContainerFm.Panel2, "splitContainerFm.Panel2");
            // 
            // treeFmLeft
            // 
            resources.ApplyResources(this.treeFmLeft, "treeFmLeft");
            this.treeFmLeft.FullRowSelect = true;
            this.treeFmLeft.ImageList = this.imageListFileMgrLeft;
            this.treeFmLeft.Name = "treeFmLeft";
            // 
            // imageListFileMgrLeft
            // 
            this.imageListFileMgrLeft.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListFileMgrLeft.ImageStream")));
            this.imageListFileMgrLeft.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListFileMgrLeft.Images.SetKeyName(0, "sec");
            this.imageListFileMgrLeft.Images.SetKeyName(1, "loading");
            this.imageListFileMgrLeft.Images.SetKeyName(2, "err");
            // 
            // listFm
            // 
            this.listFm.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader3,
            this.columnHeader2,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6});
            resources.ApplyResources(this.listFm, "listFm");
            this.listFm.FullRowSelect = true;
            this.listFm.Name = "listFm";
            this.listFm.ShowItemToolTips = true;
            this.listFm.SmallImageList = this.imageListFileTypeList;
            this.listFm.UseCompatibleStateImageBehavior = false;
            this.listFm.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            resources.ApplyResources(this.columnHeader1, "columnHeader1");
            // 
            // columnHeader3
            // 
            resources.ApplyResources(this.columnHeader3, "columnHeader3");
            // 
            // columnHeader2
            // 
            resources.ApplyResources(this.columnHeader2, "columnHeader2");
            // 
            // columnHeader4
            // 
            resources.ApplyResources(this.columnHeader4, "columnHeader4");
            // 
            // columnHeader5
            // 
            resources.ApplyResources(this.columnHeader5, "columnHeader5");
            // 
            // columnHeader6
            // 
            resources.ApplyResources(this.columnHeader6, "columnHeader6");
            // 
            // imageListFileTypeList
            // 
            this.imageListFileTypeList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListFileTypeList.ImageStream")));
            this.imageListFileTypeList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListFileTypeList.Images.SetKeyName(0, "err");
            // 
            // tabControlMain
            // 
            resources.ApplyResources(this.tabControlMain, "tabControlMain");
            this.tabControlMain.Controls.Add(this.tabPageProcCtl);
            this.tabControlMain.Controls.Add(this.tabPageKernelCtl);
            this.tabControlMain.Controls.Add(this.tabPagePerfCtl);
            this.tabControlMain.Controls.Add(this.tabPageUWPCtl);
            this.tabControlMain.Controls.Add(this.tabPageUsers);
            this.tabControlMain.Controls.Add(this.tabPageScCtl);
            this.tabControlMain.Controls.Add(this.tabPageDetals);
            this.tabControlMain.Controls.Add(this.tabPageStartCtl);
            this.tabControlMain.Controls.Add(this.tabPageFileCtl);
            this.tabControlMain.Cursor = System.Windows.Forms.Cursors.Default;
            this.tabControlMain.HotTrack = true;
            this.tabControlMain.Multiline = true;
            this.tabControlMain.Name = "tabControlMain";
            this.tabControlMain.SelectedIndex = 0;
            this.tabControlMain.Selected += new System.Windows.Forms.TabControlEventHandler(this.tabControlMain_Selected);
            // 
            // tabPageProcCtl
            // 
            this.tabPageProcCtl.Controls.Add(this.sp4);
            this.tabPageProcCtl.Controls.Add(this.btnEndProcess);
            this.tabPageProcCtl.Controls.Add(this.listProcess);
            this.tabPageProcCtl.Controls.Add(this.lbProcessCount);
            this.tabPageProcCtl.Controls.Add(this.expandFewerDetals);
            resources.ApplyResources(this.tabPageProcCtl, "tabPageProcCtl");
            this.tabPageProcCtl.Name = "tabPageProcCtl";
            this.tabPageProcCtl.UseVisualStyleBackColor = true;
            // 
            // sp4
            // 
            resources.ApplyResources(this.sp4, "sp4");
            this.sp4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(207)))), ((int)(((byte)(207)))), ((int)(((byte)(207)))));
            this.sp4.Name = "sp4";
            this.sp4.TabStop = false;
            // 
            // btnEndProcess
            // 
            resources.ApplyResources(this.btnEndProcess, "btnEndProcess");
            this.btnEndProcess.Name = "btnEndProcess";
            this.btnEndProcess.UseVisualStyleBackColor = true;
            // 
            // listProcess
            // 
            resources.ApplyResources(this.listProcess, "listProcess");
            this.listProcess.BackColor = System.Drawing.SystemColors.Window;
            this.listProcess.DrawIcon = true;
            this.listProcess.DrawUWPPausedIconIndexGetCallback = null;
            this.listProcess.FocusedType = false;
            this.listProcess.Icons = null;
            this.listProcess.ListViewItemSorter = null;
            this.listProcess.Name = "listProcess";
            this.listProcess.NoHeader = false;
            this.listProcess.SelectedItem = null;
            this.listProcess.ShowGroup = false;
            this.listProcess.Value = 0D;
            this.listProcess.XOffest = 0;
            // 
            // lbProcessCount
            // 
            resources.ApplyResources(this.lbProcessCount, "lbProcessCount");
            this.lbProcessCount.Name = "lbProcessCount";
            // 
            // expandFewerDetals
            // 
            resources.ApplyResources(this.expandFewerDetals, "expandFewerDetals");
            this.expandFewerDetals.BackColor = System.Drawing.Color.White;
            this.expandFewerDetals.Expanded = false;
            this.expandFewerDetals.Name = "expandFewerDetals";
            this.expandFewerDetals.UseVisualStyleBackColor = false;
            // 
            // tabPageKernelCtl
            // 
            this.tabPageKernelCtl.Controls.Add(this.pl_driverNotLoadTip);
            this.tabPageKernelCtl.Controls.Add(this.sp5);
            this.tabPageKernelCtl.Controls.Add(this.linkLabelShowKernelTools);
            this.tabPageKernelCtl.Controls.Add(this.lbDriversCount);
            this.tabPageKernelCtl.Controls.Add(this.listDrivers);
            resources.ApplyResources(this.tabPageKernelCtl, "tabPageKernelCtl");
            this.tabPageKernelCtl.Name = "tabPageKernelCtl";
            this.tabPageKernelCtl.UseVisualStyleBackColor = true;
            // 
            // pl_driverNotLoadTip
            // 
            resources.ApplyResources(this.pl_driverNotLoadTip, "pl_driverNotLoadTip");
            this.pl_driverNotLoadTip.Controls.Add(this.linkRestartAsAdminDriver);
            this.pl_driverNotLoadTip.Controls.Add(this.lbRestartAsAdminDriver);
            this.pl_driverNotLoadTip.Name = "pl_driverNotLoadTip";
            // 
            // linkRestartAsAdminDriver
            // 
            this.linkRestartAsAdminDriver.DisabledLinkColor = System.Drawing.SystemColors.MenuHighlight;
            resources.ApplyResources(this.linkRestartAsAdminDriver, "linkRestartAsAdminDriver");
            this.linkRestartAsAdminDriver.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.linkRestartAsAdminDriver.LinkColor = System.Drawing.SystemColors.MenuHighlight;
            this.linkRestartAsAdminDriver.Name = "linkRestartAsAdminDriver";
            this.linkRestartAsAdminDriver.TabStop = true;
            // 
            // lbRestartAsAdminDriver
            // 
            resources.ApplyResources(this.lbRestartAsAdminDriver, "lbRestartAsAdminDriver");
            this.lbRestartAsAdminDriver.Name = "lbRestartAsAdminDriver";
            // 
            // sp5
            // 
            resources.ApplyResources(this.sp5, "sp5");
            this.sp5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(207)))), ((int)(((byte)(207)))), ((int)(((byte)(207)))));
            this.sp5.Name = "sp5";
            this.sp5.TabStop = false;
            // 
            // linkLabelShowKernelTools
            // 
            resources.ApplyResources(this.linkLabelShowKernelTools, "linkLabelShowKernelTools");
            this.linkLabelShowKernelTools.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.linkLabelShowKernelTools.LinkColor = System.Drawing.Color.DodgerBlue;
            this.linkLabelShowKernelTools.Name = "linkLabelShowKernelTools";
            this.linkLabelShowKernelTools.TabStop = true;
            // 
            // lbDriversCount
            // 
            resources.ApplyResources(this.lbDriversCount, "lbDriversCount");
            this.lbDriversCount.Name = "lbDriversCount";
            // 
            // listDrivers
            // 
            resources.ApplyResources(this.listDrivers, "listDrivers");
            this.listDrivers.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.listDrivers.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader15,
            this.columnHeader16,
            this.columnHeader17,
            this.columnHeader18,
            this.columnHeader19,
            this.columnHeader20,
            this.columnHeader22,
            this.columnHeader23});
            this.listDrivers.FullRowSelect = true;
            this.listDrivers.Name = "listDrivers";
            this.listDrivers.UseCompatibleStateImageBehavior = false;
            this.listDrivers.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader15
            // 
            resources.ApplyResources(this.columnHeader15, "columnHeader15");
            // 
            // columnHeader16
            // 
            resources.ApplyResources(this.columnHeader16, "columnHeader16");
            // 
            // columnHeader17
            // 
            resources.ApplyResources(this.columnHeader17, "columnHeader17");
            // 
            // columnHeader18
            // 
            resources.ApplyResources(this.columnHeader18, "columnHeader18");
            // 
            // columnHeader19
            // 
            resources.ApplyResources(this.columnHeader19, "columnHeader19");
            // 
            // columnHeader20
            // 
            resources.ApplyResources(this.columnHeader20, "columnHeader20");
            // 
            // columnHeader22
            // 
            resources.ApplyResources(this.columnHeader22, "columnHeader22");
            // 
            // columnHeader23
            // 
            resources.ApplyResources(this.columnHeader23, "columnHeader23");
            // 
            // tabPagePerfCtl
            // 
            this.tabPagePerfCtl.Controls.Add(this.linkLabelOpenPerfMon);
            this.tabPagePerfCtl.Controls.Add(this.splitContainerPerfCtls);
            resources.ApplyResources(this.tabPagePerfCtl, "tabPagePerfCtl");
            this.tabPagePerfCtl.Name = "tabPagePerfCtl";
            this.tabPagePerfCtl.UseVisualStyleBackColor = true;
            // 
            // linkLabelOpenPerfMon
            // 
            resources.ApplyResources(this.linkLabelOpenPerfMon, "linkLabelOpenPerfMon");
            this.linkLabelOpenPerfMon.DisabledLinkColor = System.Drawing.SystemColors.MenuHighlight;
            this.linkLabelOpenPerfMon.Image = global::PCMgr.Properties.Resources.icoResourceMon;
            this.linkLabelOpenPerfMon.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.linkLabelOpenPerfMon.LinkColor = System.Drawing.SystemColors.MenuHighlight;
            this.linkLabelOpenPerfMon.Name = "linkLabelOpenPerfMon";
            this.linkLabelOpenPerfMon.TabStop = true;
            // 
            // tabPageUWPCtl
            // 
            this.tabPageUWPCtl.Controls.Add(this.pl_UWPEnumFailTip);
            this.tabPageUWPCtl.Controls.Add(this.listUwpApps);
            resources.ApplyResources(this.tabPageUWPCtl, "tabPageUWPCtl");
            this.tabPageUWPCtl.Name = "tabPageUWPCtl";
            this.tabPageUWPCtl.UseVisualStyleBackColor = true;
            // 
            // pl_UWPEnumFailTip
            // 
            resources.ApplyResources(this.pl_UWPEnumFailTip, "pl_UWPEnumFailTip");
            this.pl_UWPEnumFailTip.Controls.Add(this.lbUWPEnumFailText);
            this.pl_UWPEnumFailTip.Name = "pl_UWPEnumFailTip";
            // 
            // lbUWPEnumFailText
            // 
            resources.ApplyResources(this.lbUWPEnumFailText, "lbUWPEnumFailText");
            this.lbUWPEnumFailText.Name = "lbUWPEnumFailText";
            // 
            // listUwpApps
            // 
            resources.ApplyResources(this.listUwpApps, "listUwpApps");
            this.listUwpApps.BackColor = System.Drawing.SystemColors.Window;
            this.listUwpApps.DrawIcon = true;
            this.listUwpApps.DrawUWPPausedIconIndexGetCallback = null;
            this.listUwpApps.FocusedType = false;
            this.listUwpApps.ListViewItemSorter = null;
            this.listUwpApps.Name = "listUwpApps";
            this.listUwpApps.NoHeader = false;
            this.listUwpApps.SelectedItem = null;
            this.listUwpApps.ShowGroup = false;
            this.listUwpApps.Value = 0D;
            this.listUwpApps.XOffest = 0;
            // 
            // tabPageUsers
            // 
            this.tabPageUsers.Controls.Add(this.listUsers);
            resources.ApplyResources(this.tabPageUsers, "tabPageUsers");
            this.tabPageUsers.Name = "tabPageUsers";
            this.tabPageUsers.UseVisualStyleBackColor = true;
            // 
            // listUsers
            // 
            resources.ApplyResources(this.listUsers, "listUsers");
            this.listUsers.BackColor = System.Drawing.Color.White;
            this.listUsers.DrawIcon = true;
            this.listUsers.DrawUWPPausedIconIndexGetCallback = null;
            this.listUsers.FocusedType = false;
            this.listUsers.ListViewItemSorter = null;
            this.listUsers.Name = "listUsers";
            this.listUsers.NoHeader = false;
            this.listUsers.SelectedItem = null;
            this.listUsers.ShowGroup = false;
            this.listUsers.Value = 0D;
            this.listUsers.XOffest = 0;
            // 
            // tabPageScCtl
            // 
            this.tabPageScCtl.Controls.Add(this.pl_ScNeedAdminTip);
            this.tabPageScCtl.Controls.Add(this.sp2);
            this.tabPageScCtl.Controls.Add(this.linkOpenScMsc);
            this.tabPageScCtl.Controls.Add(this.listService);
            this.tabPageScCtl.Controls.Add(this.lbServicesCount);
            resources.ApplyResources(this.tabPageScCtl, "tabPageScCtl");
            this.tabPageScCtl.Name = "tabPageScCtl";
            this.tabPageScCtl.UseVisualStyleBackColor = true;
            // 
            // pl_ScNeedAdminTip
            // 
            resources.ApplyResources(this.pl_ScNeedAdminTip, "pl_ScNeedAdminTip");
            this.pl_ScNeedAdminTip.Controls.Add(this.linkRebootAsAdmin);
            this.pl_ScNeedAdminTip.Controls.Add(this.lbScNeedAdminTip);
            this.pl_ScNeedAdminTip.Name = "pl_ScNeedAdminTip";
            // 
            // linkRebootAsAdmin
            // 
            this.linkRebootAsAdmin.DisabledLinkColor = System.Drawing.SystemColors.MenuHighlight;
            resources.ApplyResources(this.linkRebootAsAdmin, "linkRebootAsAdmin");
            this.linkRebootAsAdmin.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.linkRebootAsAdmin.LinkColor = System.Drawing.SystemColors.MenuHighlight;
            this.linkRebootAsAdmin.Name = "linkRebootAsAdmin";
            this.linkRebootAsAdmin.TabStop = true;
            // 
            // lbScNeedAdminTip
            // 
            resources.ApplyResources(this.lbScNeedAdminTip, "lbScNeedAdminTip");
            this.lbScNeedAdminTip.Name = "lbScNeedAdminTip";
            // 
            // sp2
            // 
            resources.ApplyResources(this.sp2, "sp2");
            this.sp2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(207)))), ((int)(((byte)(207)))), ((int)(((byte)(207)))));
            this.sp2.Name = "sp2";
            this.sp2.TabStop = false;
            // 
            // linkOpenScMsc
            // 
            resources.ApplyResources(this.linkOpenScMsc, "linkOpenScMsc");
            this.linkOpenScMsc.DisabledLinkColor = System.Drawing.SystemColors.MenuHighlight;
            this.linkOpenScMsc.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.linkOpenScMsc.LinkColor = System.Drawing.SystemColors.MenuHighlight;
            this.linkOpenScMsc.Name = "linkOpenScMsc";
            this.linkOpenScMsc.TabStop = true;
            // 
            // listService
            // 
            resources.ApplyResources(this.listService, "listService");
            this.listService.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.listService.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9,
            this.columnHeader10,
            this.columnHeader11,
            this.columnHeader12,
            this.columnHeader13,
            this.columnHeader14,
            this.columnHeader21});
            this.listService.FullRowSelect = true;
            this.listService.MultiSelect = false;
            this.listService.Name = "listService";
            this.listService.UseCompatibleStateImageBehavior = false;
            this.listService.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader7
            // 
            resources.ApplyResources(this.columnHeader7, "columnHeader7");
            // 
            // columnHeader8
            // 
            resources.ApplyResources(this.columnHeader8, "columnHeader8");
            // 
            // columnHeader9
            // 
            resources.ApplyResources(this.columnHeader9, "columnHeader9");
            // 
            // columnHeader10
            // 
            resources.ApplyResources(this.columnHeader10, "columnHeader10");
            // 
            // columnHeader11
            // 
            resources.ApplyResources(this.columnHeader11, "columnHeader11");
            // 
            // columnHeader12
            // 
            resources.ApplyResources(this.columnHeader12, "columnHeader12");
            // 
            // columnHeader13
            // 
            resources.ApplyResources(this.columnHeader13, "columnHeader13");
            // 
            // columnHeader14
            // 
            resources.ApplyResources(this.columnHeader14, "columnHeader14");
            // 
            // columnHeader21
            // 
            resources.ApplyResources(this.columnHeader21, "columnHeader21");
            // 
            // lbServicesCount
            // 
            resources.ApplyResources(this.lbServicesCount, "lbServicesCount");
            this.lbServicesCount.Name = "lbServicesCount";
            // 
            // tabPageDetals
            // 
            this.tabPageDetals.Controls.Add(this.check_showAllProcess);
            this.tabPageDetals.Controls.Add(this.btnEndProcessDetals);
            this.tabPageDetals.Controls.Add(this.listProcessDetals);
            resources.ApplyResources(this.tabPageDetals, "tabPageDetals");
            this.tabPageDetals.Name = "tabPageDetals";
            this.tabPageDetals.UseVisualStyleBackColor = true;
            // 
            // btnEndProcessDetals
            // 
            resources.ApplyResources(this.btnEndProcessDetals, "btnEndProcessDetals");
            this.btnEndProcessDetals.Name = "btnEndProcessDetals";
            this.btnEndProcessDetals.UseVisualStyleBackColor = true;
            // 
            // listProcessDetals
            // 
            this.listProcessDetals.AllowColumnReorder = true;
            resources.ApplyResources(this.listProcessDetals, "listProcessDetals");
            this.listProcessDetals.FullRowSelect = true;
            this.listProcessDetals.MultiSelect = false;
            this.listProcessDetals.Name = "listProcessDetals";
            this.listProcessDetals.ShowItemToolTips = true;
            this.listProcessDetals.SmallImageList = this.imageListProcessDetalsIcons;
            this.listProcessDetals.UseCompatibleStateImageBehavior = false;
            this.listProcessDetals.View = System.Windows.Forms.View.Details;
            // 
            // imageListProcessDetalsIcons
            // 
            this.imageListProcessDetalsIcons.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListProcessDetalsIcons.ImageStream")));
            this.imageListProcessDetalsIcons.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListProcessDetalsIcons.Images.SetKeyName(0, "err");
            // 
            // tabPageStartCtl
            // 
            this.tabPageStartCtl.Controls.Add(this.pl_bios_time);
            this.tabPageStartCtl.Controls.Add(this.listStartup);
            resources.ApplyResources(this.tabPageStartCtl, "tabPageStartCtl");
            this.tabPageStartCtl.Name = "tabPageStartCtl";
            this.tabPageStartCtl.UseVisualStyleBackColor = true;
            // 
            // pl_bios_time
            // 
            resources.ApplyResources(this.pl_bios_time, "pl_bios_time");
            this.pl_bios_time.Controls.Add(this.lbBiosTime);
            this.pl_bios_time.Controls.Add(this.lbBiosTimeText);
            this.pl_bios_time.Name = "pl_bios_time";
            // 
            // lbBiosTime
            // 
            this.lbBiosTime.AutoEllipsis = true;
            this.lbBiosTime.ForeColor = System.Drawing.Color.Black;
            resources.ApplyResources(this.lbBiosTime, "lbBiosTime");
            this.lbBiosTime.Name = "lbBiosTime";
            // 
            // lbBiosTimeText
            // 
            this.lbBiosTimeText.AutoEllipsis = true;
            this.lbBiosTimeText.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(96)))), ((int)(((byte)(122)))));
            resources.ApplyResources(this.lbBiosTimeText, "lbBiosTimeText");
            this.lbBiosTimeText.Name = "lbBiosTimeText";
            // 
            // listStartup
            // 
            resources.ApplyResources(this.listStartup, "listStartup");
            this.listStartup.BackColor = System.Drawing.Color.White;
            this.listStartup.DrawIcon = true;
            this.listStartup.DrawUWPPausedIconIndexGetCallback = null;
            this.listStartup.FocusedType = false;
            this.listStartup.ListViewItemSorter = null;
            this.listStartup.Name = "listStartup";
            this.listStartup.NoHeader = false;
            this.listStartup.SelectedItem = null;
            this.listStartup.ShowGroup = false;
            this.listStartup.Value = 0D;
            this.listStartup.XOffest = 0;
            // 
            // tabPageFileCtl
            // 
            this.tabPageFileCtl.Controls.Add(this.lbFileMgrStatus);
            this.tabPageFileCtl.Controls.Add(this.btnFmAddGoto);
            this.tabPageFileCtl.Controls.Add(this.textBoxFmCurrent);
            this.tabPageFileCtl.Controls.Add(this.splitContainerFm);
            resources.ApplyResources(this.tabPageFileCtl, "tabPageFileCtl");
            this.tabPageFileCtl.Name = "tabPageFileCtl";
            this.tabPageFileCtl.UseVisualStyleBackColor = true;
            // 
            // lbFileMgrStatus
            // 
            resources.ApplyResources(this.lbFileMgrStatus, "lbFileMgrStatus");
            this.lbFileMgrStatus.Name = "lbFileMgrStatus";
            // 
            // btnFmAddGoto
            // 
            resources.ApplyResources(this.btnFmAddGoto, "btnFmAddGoto");
            this.btnFmAddGoto.Name = "btnFmAddGoto";
            this.toolTip.SetToolTip(this.btnFmAddGoto, resources.GetString("btnFmAddGoto.ToolTip"));
            this.btnFmAddGoto.UseVisualStyleBackColor = true;
            // 
            // textBoxFmCurrent
            // 
            resources.ApplyResources(this.textBoxFmCurrent, "textBoxFmCurrent");
            this.textBoxFmCurrent.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBoxFmCurrent.Name = "textBoxFmCurrent";
            // 
            // lbStartingStatus
            // 
            resources.ApplyResources(this.lbStartingStatus, "lbStartingStatus");
            this.lbStartingStatus.AutoEllipsis = true;
            this.lbStartingStatus.Name = "lbStartingStatus";
            // 
            // spBottom
            // 
            resources.ApplyResources(this.spBottom, "spBottom");
            this.spBottom.BackColor = System.Drawing.Color.DarkGray;
            this.spBottom.Name = "spBottom";
            this.spBottom.TabStop = false;
            // 
            // contextMenuStripUWP
            // 
            this.contextMenuStripUWP.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStripUWP.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开应用ToolStripMenuItem,
            this.卸载应用ToolStripMenuItem,
            this.打开安装位置ToolStripMenuItem,
            this.复制名称ToolStripMenuItem,
            this.复制完整名称ToolStripMenuItem,
            this.复制发布者ToolStripMenuItem});
            this.contextMenuStripUWP.Name = "contextMenuStripUWP";
            this.contextMenuStripUWP.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            resources.ApplyResources(this.contextMenuStripUWP, "contextMenuStripUWP");
            // 
            // 打开应用ToolStripMenuItem
            // 
            this.打开应用ToolStripMenuItem.Name = "打开应用ToolStripMenuItem";
            resources.ApplyResources(this.打开应用ToolStripMenuItem, "打开应用ToolStripMenuItem");
            // 
            // 卸载应用ToolStripMenuItem
            // 
            this.卸载应用ToolStripMenuItem.Name = "卸载应用ToolStripMenuItem";
            resources.ApplyResources(this.卸载应用ToolStripMenuItem, "卸载应用ToolStripMenuItem");
            // 
            // 打开安装位置ToolStripMenuItem
            // 
            this.打开安装位置ToolStripMenuItem.Name = "打开安装位置ToolStripMenuItem";
            resources.ApplyResources(this.打开安装位置ToolStripMenuItem, "打开安装位置ToolStripMenuItem");
            // 
            // 复制名称ToolStripMenuItem
            // 
            this.复制名称ToolStripMenuItem.Name = "复制名称ToolStripMenuItem";
            resources.ApplyResources(this.复制名称ToolStripMenuItem, "复制名称ToolStripMenuItem");
            // 
            // 复制完整名称ToolStripMenuItem
            // 
            this.复制完整名称ToolStripMenuItem.Name = "复制完整名称ToolStripMenuItem";
            resources.ApplyResources(this.复制完整名称ToolStripMenuItem, "复制完整名称ToolStripMenuItem");
            // 
            // 复制发布者ToolStripMenuItem
            // 
            this.复制发布者ToolStripMenuItem.Name = "复制发布者ToolStripMenuItem";
            resources.ApplyResources(this.复制发布者ToolStripMenuItem, "复制发布者ToolStripMenuItem");
            // 
            // listApps
            // 
            resources.ApplyResources(this.listApps, "listApps");
            this.listApps.DrawIcon = true;
            this.listApps.DrawUWPPausedIconIndexGetCallback = null;
            this.listApps.FocusedType = false;
            this.listApps.ListViewItemSorter = null;
            this.listApps.Name = "listApps";
            this.listApps.NoHeader = false;
            this.listApps.SelectedItem = null;
            this.listApps.ShowGroup = false;
            this.listApps.Value = 0D;
            this.listApps.XOffest = 0;
            // 
            // pl_simple
            // 
            this.pl_simple.Controls.Add(this.expandMoreDetals);
            this.pl_simple.Controls.Add(this.btnEndTaskSimple);
            this.pl_simple.Controls.Add(this.listApps);
            resources.ApplyResources(this.pl_simple, "pl_simple");
            this.pl_simple.Name = "pl_simple";
            // 
            // expandMoreDetals
            // 
            resources.ApplyResources(this.expandMoreDetals, "expandMoreDetals");
            this.expandMoreDetals.BackColor = System.Drawing.Color.White;
            this.expandMoreDetals.Expanded = false;
            this.expandMoreDetals.Name = "expandMoreDetals";
            this.expandMoreDetals.UseVisualStyleBackColor = false;
            // 
            // btnEndTaskSimple
            // 
            resources.ApplyResources(this.btnEndTaskSimple, "btnEndTaskSimple");
            this.btnEndTaskSimple.Name = "btnEndTaskSimple";
            this.btnEndTaskSimple.UseVisualStyleBackColor = true;
            // 
            // contextMenuStripProcDetalsCol
            // 
            this.contextMenuStripProcDetalsCol.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStripProcDetalsCol.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.隐藏列ToolStripMenuItem,
            this.选择列ToolStripMenuItem,
            this.toolStripSeparator1,
            this.将此列调整为合适大小ToolStripMenuItem});
            this.contextMenuStripProcDetalsCol.Name = "contextMenuStripProcDetalsCol";
            this.contextMenuStripProcDetalsCol.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            resources.ApplyResources(this.contextMenuStripProcDetalsCol, "contextMenuStripProcDetalsCol");
            // 
            // 隐藏列ToolStripMenuItem
            // 
            this.隐藏列ToolStripMenuItem.Name = "隐藏列ToolStripMenuItem";
            resources.ApplyResources(this.隐藏列ToolStripMenuItem, "隐藏列ToolStripMenuItem");
            // 
            // 选择列ToolStripMenuItem
            // 
            this.选择列ToolStripMenuItem.Name = "选择列ToolStripMenuItem";
            resources.ApplyResources(this.选择列ToolStripMenuItem, "选择列ToolStripMenuItem");
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            resources.ApplyResources(this.toolStripSeparator1, "toolStripSeparator1");
            // 
            // 将此列调整为合适大小ToolStripMenuItem
            // 
            this.将此列调整为合适大小ToolStripMenuItem.Name = "将此列调整为合适大小ToolStripMenuItem";
            resources.ApplyResources(this.将此列调整为合适大小ToolStripMenuItem, "将此列调整为合适大小ToolStripMenuItem");
            // 
            // contextMenuStripTray
            // 
            this.contextMenuStripTray.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStripTray.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.显示隐藏主界面ToolStripMenuItem,
            this.退出程序ToolStripMenuItem});
            this.contextMenuStripTray.Name = "contextMenuStripTray";
            this.contextMenuStripTray.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            resources.ApplyResources(this.contextMenuStripTray, "contextMenuStripTray");
            this.contextMenuStripTray.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStripTray_Opening);
            // 
            // 显示隐藏主界面ToolStripMenuItem
            // 
            this.显示隐藏主界面ToolStripMenuItem.Name = "显示隐藏主界面ToolStripMenuItem";
            resources.ApplyResources(this.显示隐藏主界面ToolStripMenuItem, "显示隐藏主界面ToolStripMenuItem");
            this.显示隐藏主界面ToolStripMenuItem.Click += new System.EventHandler(this.显示隐藏主界面ToolStripMenuItem_Click);
            // 
            // 退出程序ToolStripMenuItem
            // 
            this.退出程序ToolStripMenuItem.Name = "退出程序ToolStripMenuItem";
            resources.ApplyResources(this.退出程序ToolStripMenuItem, "退出程序ToolStripMenuItem");
            this.退出程序ToolStripMenuItem.Click += new System.EventHandler(this.退出程序ToolStripMenuItem_Click);
            // 
            // pl_perfGridHost
            // 
            resources.ApplyResources(this.pl_perfGridHost, "pl_perfGridHost");
            this.pl_perfGridHost.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.pl_perfGridHost.Name = "pl_perfGridHost";
            // 
            // contextMenuStripMainHeader
            // 
            this.contextMenuStripMainHeader.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStripMainHeader.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSeparator2,
            this.资源值ToolStripMenuItem});
            this.contextMenuStripMainHeader.Name = "contextMenuStripMainHeader";
            this.contextMenuStripMainHeader.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            resources.ApplyResources(this.contextMenuStripMainHeader, "contextMenuStripMainHeader");
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            resources.ApplyResources(this.toolStripSeparator2, "toolStripSeparator2");
            // 
            // 资源值ToolStripMenuItem
            // 
            this.资源值ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.内存ToolStripMenuItem,
            this.磁盘ToolStripMenuItem,
            this.网络ToolStripMenuItem});
            resources.ApplyResources(this.资源值ToolStripMenuItem, "资源值ToolStripMenuItem");
            this.资源值ToolStripMenuItem.Name = "资源值ToolStripMenuItem";
            // 
            // 内存ToolStripMenuItem
            // 
            this.内存ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.百分比ToolStripMenuItemRam,
            this.值ToolStripMenuItemRam});
            this.内存ToolStripMenuItem.Name = "内存ToolStripMenuItem";
            resources.ApplyResources(this.内存ToolStripMenuItem, "内存ToolStripMenuItem");
            // 
            // 百分比ToolStripMenuItemRam
            // 
            resources.ApplyResources(this.百分比ToolStripMenuItemRam, "百分比ToolStripMenuItemRam");
            this.百分比ToolStripMenuItemRam.Name = "百分比ToolStripMenuItemRam";
            // 
            // 值ToolStripMenuItemRam
            // 
            this.值ToolStripMenuItemRam.Checked = true;
            this.值ToolStripMenuItemRam.CheckState = System.Windows.Forms.CheckState.Checked;
            resources.ApplyResources(this.值ToolStripMenuItemRam, "值ToolStripMenuItemRam");
            this.值ToolStripMenuItemRam.Name = "值ToolStripMenuItemRam";
            // 
            // 磁盘ToolStripMenuItem
            // 
            this.磁盘ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.百分比ToolStripMenuItemDisk,
            this.值ToolStripMenuItemDisk});
            this.磁盘ToolStripMenuItem.Name = "磁盘ToolStripMenuItem";
            resources.ApplyResources(this.磁盘ToolStripMenuItem, "磁盘ToolStripMenuItem");
            // 
            // 百分比ToolStripMenuItemDisk
            // 
            resources.ApplyResources(this.百分比ToolStripMenuItemDisk, "百分比ToolStripMenuItemDisk");
            this.百分比ToolStripMenuItemDisk.Name = "百分比ToolStripMenuItemDisk";
            // 
            // 值ToolStripMenuItemDisk
            // 
            this.值ToolStripMenuItemDisk.Checked = true;
            this.值ToolStripMenuItemDisk.CheckState = System.Windows.Forms.CheckState.Checked;
            resources.ApplyResources(this.值ToolStripMenuItemDisk, "值ToolStripMenuItemDisk");
            this.值ToolStripMenuItemDisk.Name = "值ToolStripMenuItemDisk";
            // 
            // 网络ToolStripMenuItem
            // 
            this.网络ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.百分比ToolStripMenuItemNet,
            this.值ToolStripMenuItemNet});
            this.网络ToolStripMenuItem.Name = "网络ToolStripMenuItem";
            resources.ApplyResources(this.网络ToolStripMenuItem, "网络ToolStripMenuItem");
            // 
            // 百分比ToolStripMenuItemNet
            // 
            resources.ApplyResources(this.百分比ToolStripMenuItemNet, "百分比ToolStripMenuItemNet");
            this.百分比ToolStripMenuItemNet.Name = "百分比ToolStripMenuItemNet";
            // 
            // 值ToolStripMenuItemNet
            // 
            this.值ToolStripMenuItemNet.Checked = true;
            this.值ToolStripMenuItemNet.CheckState = System.Windows.Forms.CheckState.Checked;
            resources.ApplyResources(this.值ToolStripMenuItemNet, "值ToolStripMenuItemNet");
            this.值ToolStripMenuItemNet.Name = "值ToolStripMenuItemNet";
            // 
            // contextMenuStripPerfListLeft
            // 
            this.contextMenuStripPerfListLeft.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStripPerfListLeft.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.隐藏图形ToolStripMenuItem});
            this.contextMenuStripPerfListLeft.Name = "contextMenuStripMainHeader";
            this.contextMenuStripPerfListLeft.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            resources.ApplyResources(this.contextMenuStripPerfListLeft, "contextMenuStripPerfListLeft");
            // 
            // 隐藏图形ToolStripMenuItem
            // 
            resources.ApplyResources(this.隐藏图形ToolStripMenuItem, "隐藏图形ToolStripMenuItem");
            this.隐藏图形ToolStripMenuItem.Name = "隐藏图形ToolStripMenuItem";
            // 
            // fileSystemWatcher
            // 
            this.fileSystemWatcher.EnableRaisingEvents = true;
            this.fileSystemWatcher.SynchronizingObject = this;
            // 
            // notifyIcon
            // 
            this.notifyIcon.ContextMenuStrip = this.contextMenuStripTray;
            resources.ApplyResources(this.notifyIcon, "notifyIcon");
            this.notifyIcon.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.notifyIcon_MouseDoubleClick);
            this.notifyIcon.MouseMove += new System.Windows.Forms.MouseEventHandler(this.notifyIcon_MouseMove);
            // 
            // check_showAllProcess
            // 
            resources.ApplyResources(this.check_showAllProcess, "check_showAllProcess");
            this.check_showAllProcess.Name = "check_showAllProcess";
            this.check_showAllProcess.UseVisualStyleBackColor = true;
            // 
            // FormMain
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.Controls.Add(this.spBottom);
            this.Controls.Add(this.tabControlMain);
            this.Controls.Add(this.pl_simple);
            this.Controls.Add(this.pl_perfGridHost);
            this.Controls.Add(this.lbStartingStatus);
            this.Cursor = System.Windows.Forms.Cursors.AppStarting;
            this.Name = "FormMain";
            this.Activated += new System.EventHandler(this.FormMain_Activated);
            this.Deactivate += new System.EventHandler(this.FormMain_Deactivate);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormMain_FormClosing);
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.Shown += new System.EventHandler(this.FormMain_Shown);
            this.VisibleChanged += new System.EventHandler(this.FormMain_VisibleChanged);
            this.splitContainerPerfCtls.Panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerPerfCtls)).EndInit();
            this.splitContainerPerfCtls.ResumeLayout(false);
            this.splitContainerFm.Panel1.ResumeLayout(false);
            this.splitContainerFm.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerFm)).EndInit();
            this.splitContainerFm.ResumeLayout(false);
            this.tabControlMain.ResumeLayout(false);
            this.tabPageProcCtl.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.sp4)).EndInit();
            this.tabPageKernelCtl.ResumeLayout(false);
            this.tabPageKernelCtl.PerformLayout();
            this.pl_driverNotLoadTip.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.sp5)).EndInit();
            this.tabPagePerfCtl.ResumeLayout(false);
            this.tabPageUWPCtl.ResumeLayout(false);
            this.pl_UWPEnumFailTip.ResumeLayout(false);
            this.tabPageUsers.ResumeLayout(false);
            this.tabPageScCtl.ResumeLayout(false);
            this.pl_ScNeedAdminTip.ResumeLayout(false);
            this.pl_ScNeedAdminTip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sp2)).EndInit();
            this.tabPageDetals.ResumeLayout(false);
            this.tabPageStartCtl.ResumeLayout(false);
            this.pl_bios_time.ResumeLayout(false);
            this.tabPageFileCtl.ResumeLayout(false);
            this.tabPageFileCtl.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spBottom)).EndInit();
            this.contextMenuStripUWP.ResumeLayout(false);
            this.pl_simple.ResumeLayout(false);
            this.contextMenuStripProcDetalsCol.ResumeLayout(false);
            this.contextMenuStripTray.ResumeLayout(false);
            this.contextMenuStripMainHeader.ResumeLayout(false);
            this.contextMenuStripPerfListLeft.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.TabControl tabControlMain;
        public System.Windows.Forms.TabPage tabPageProcCtl;
        public System.Windows.Forms.TabPage tabPageKernelCtl;
        public System.Windows.Forms.PictureBox spBottom;
        public System.Windows.Forms.Button btnEndProcess;
        public Ctls.TaskMgrList listProcess;
        public System.Windows.Forms.Label lbProcessCount;
        public System.Windows.Forms.Label lbDriversCount;
        public System.Windows.Forms.TabPage tabPageScCtl;
        public System.Windows.Forms.TabPage tabPageStartCtl;
        public System.Windows.Forms.TabPage tabPageFileCtl;
        public System.Windows.Forms.SplitContainer splitContainerFm;
        public System.Windows.Forms.TreeView treeFmLeft;
        public System.Windows.Forms.ListView listFm;
        public System.Windows.Forms.ColumnHeader columnHeader1;
        public System.Windows.Forms.ColumnHeader columnHeader2;
        public System.Windows.Forms.ColumnHeader columnHeader3;
        public System.Windows.Forms.ColumnHeader columnHeader4;
        public System.Windows.Forms.ColumnHeader columnHeader5;
        public System.Windows.Forms.ColumnHeader columnHeader6;
        public System.Windows.Forms.ImageList imageListFileMgrLeft;
        public System.Windows.Forms.TextBox textBoxFmCurrent;
        public System.Windows.Forms.ImageList imageListFileTypeList;
        public System.Windows.Forms.Button btnFmAddGoto;
        public System.Windows.Forms.ToolTip toolTip;
        public System.Windows.Forms.Label lbFileMgrStatus;
        public System.IO.FileSystemWatcher fileSystemWatcher;
        public System.Windows.Forms.ListView listService;
        public System.Windows.Forms.ColumnHeader columnHeader7;
        public System.Windows.Forms.ColumnHeader columnHeader8;
        public System.Windows.Forms.ColumnHeader columnHeader9;
        public System.Windows.Forms.ColumnHeader columnHeader10;
        public System.Windows.Forms.ColumnHeader columnHeader11;
        public System.Windows.Forms.ColumnHeader columnHeader12;
        public System.Windows.Forms.PictureBox sp2;
        public System.Windows.Forms.LinkLabel linkOpenScMsc;
        public System.Windows.Forms.Label lbServicesCount;
        public System.Windows.Forms.Panel pl_ScNeedAdminTip;
        public System.Windows.Forms.LinkLabel linkRebootAsAdmin;
        public System.Windows.Forms.Label lbScNeedAdminTip;
        public System.Windows.Forms.ColumnHeader columnHeader13;
        public System.Windows.Forms.ColumnHeader columnHeader14;
        public System.Windows.Forms.TabPage tabPageUWPCtl;
        public Ctls.TaskMgrList listUwpApps;
        public System.Windows.Forms.Panel pl_UWPEnumFailTip;
        public System.Windows.Forms.Label lbUWPEnumFailText;
        public System.Windows.Forms.TabPage tabPagePerfCtl;
        public System.Windows.Forms.SplitContainer splitContainerPerfCtls;
        public Ctls.PerformanceList performanceLeftList;
        public System.Windows.Forms.Panel sp3;
        public System.Windows.Forms.NotifyIcon notifyIcon;
        public System.Windows.Forms.Panel pl_driverNotLoadTip;
        public System.Windows.Forms.LinkLabel linkRestartAsAdminDriver;
        public System.Windows.Forms.Label lbRestartAsAdminDriver;
        public System.Windows.Forms.ColumnHeader columnHeader21;
        public System.Windows.Forms.ListView listDrivers;
        public Ctls.TaskMgrList listStartup;
        public System.Windows.Forms.ColumnHeader columnHeader15;
        public System.Windows.Forms.ColumnHeader columnHeader16;
        public System.Windows.Forms.ColumnHeader columnHeader17;
        public System.Windows.Forms.ColumnHeader columnHeader18;
        public System.Windows.Forms.ColumnHeader columnHeader19;
        public System.Windows.Forms.ColumnHeader columnHeader20;
        public System.Windows.Forms.ColumnHeader columnHeader22;
        public System.Windows.Forms.ColumnHeader columnHeader23;
        public System.Windows.Forms.ContextMenuStrip contextMenuStripUWP;
        public System.Windows.Forms.ToolStripMenuItem 打开应用ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 卸载应用ToolStripMenuItem;
        public System.Windows.Forms.LinkLabel linkLabelOpenPerfMon;
        public System.Windows.Forms.ToolStripMenuItem 打开安装位置ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 复制名称ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 复制完整名称ToolStripMenuItem;
        public System.Windows.Forms.Label lbStartingStatus;
        public System.Windows.Forms.PictureBox sp5;
        public System.Windows.Forms.LinkLabel linkLabelShowKernelTools;
        public System.Windows.Forms.PictureBox sp4;
        public Aero.ExpandButton expandFewerDetals;
        public System.Windows.Forms.Panel pl_simple;
        public Aero.ExpandButton expandMoreDetals;
        public System.Windows.Forms.Button btnEndTaskSimple;
        public Ctls.TaskMgrList listApps;
        public System.Windows.Forms.ToolStripMenuItem 复制发布者ToolStripMenuItem;
        public System.Windows.Forms.TabPage tabPageDetals;
        public System.Windows.Forms.ListView listProcessDetals;
        public System.Windows.Forms.Button btnEndProcessDetals;
        public System.Windows.Forms.ImageList imageListProcessDetalsIcons;
        public System.Windows.Forms.ContextMenuStrip contextMenuStripProcDetalsCol;
        public System.Windows.Forms.ToolStripMenuItem 隐藏列ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 选择列ToolStripMenuItem;
        public System.Windows.Forms.TabPage tabPageUsers;
        public Ctls.TaskMgrList listUsers;
        public System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        public System.Windows.Forms.ToolStripMenuItem 将此列调整为合适大小ToolStripMenuItem;
        public System.Windows.Forms.ContextMenuStrip contextMenuStripTray;
        public System.Windows.Forms.ToolStripMenuItem 显示隐藏主界面ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 退出程序ToolStripMenuItem;
        public System.Windows.Forms.Panel pl_perfGridHost;
        public System.Windows.Forms.ContextMenuStrip contextMenuStripMainHeader;
        public System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        public System.Windows.Forms.ToolStripMenuItem 资源值ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 内存ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 百分比ToolStripMenuItemRam;
        public System.Windows.Forms.ToolStripMenuItem 值ToolStripMenuItemRam;
        public System.Windows.Forms.ToolStripMenuItem 磁盘ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 百分比ToolStripMenuItemDisk;
        public System.Windows.Forms.ToolStripMenuItem 值ToolStripMenuItemDisk;
        public System.Windows.Forms.ToolStripMenuItem 网络ToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem 百分比ToolStripMenuItemNet;
        public System.Windows.Forms.ToolStripMenuItem 值ToolStripMenuItemNet;
        public System.Windows.Forms.ContextMenuStrip contextMenuStripPerfListLeft;
        private System.Windows.Forms.Label lbBiosTimeText;
        public System.Windows.Forms.Panel pl_bios_time;
        public System.Windows.Forms.Label lbBiosTime;
        public System.Windows.Forms.ToolStripMenuItem 隐藏图形ToolStripMenuItem;
        public System.Windows.Forms.CheckBox check_showAllProcess;
    }
}

