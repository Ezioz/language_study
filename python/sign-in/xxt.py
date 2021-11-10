# -*- coding:utf-8 -*-

import click
click.secho(banner, fg='red')
@click.command(context_settings=CONTEXT_SETTINGS)
@click.option('-i', '--info', is_flag=true, help='漏洞信息简介')