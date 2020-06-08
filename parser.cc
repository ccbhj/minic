// A Bison parser, made by GNU Bison 3.6.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 36 "parser.y"

#include "tokens.h"
#include "ast.h"
#include <iostream>
#include "context.h"
#include "driver.h"

#undef yylex
#define yylex drv.scanner->yylex

using ccbhj::BiOpt;
using ccbhj::UaOpt;
using ccbhj::Type;
using std::cout;
using std::endl;

#line 63 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.y"
namespace ccbhj {
#line 156 "parser.cc"

  /// Build a parser object.
  Parser::Parser (Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 32 "parser.y"
{
    yyla.location.begin.filename = yyla.location.end.filename = &drv.output;
}

#line 494 "parser.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 107 "parser.y"
                          { drv.ctx->programBlock = (yystack_[0].value.BLOCK); }
#line 632 "parser.cc"
    break;

  case 3:
#line 108 "parser.y"
                { cout << "empty file to parse" << endl; }
#line 638 "parser.cc"
    break;

  case 4:
#line 111 "parser.y"
               { (yylhs.value.IDENT) = new IdentifierNode((yystack_[0].value.STR)); }
#line 644 "parser.cc"
    break;

  case 5:
#line 115 "parser.y"
                               {    (yylhs.value.BLOCK) = new BlockNode(); (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 650 "parser.cc"
    break;

  case 6:
#line 116 "parser.y"
                                                   { (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 656 "parser.cc"
    break;

  case 7:
#line 119 "parser.y"
                              { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 662 "parser.cc"
    break;

  case 8:
#line 120 "parser.y"
                               { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 668 "parser.cc"
    break;

  case 9:
#line 123 "parser.y"
                                  { (yylhs.value.STMT) = new Formal((yystack_[2].value.TYPE), (yystack_[1].value.IDENT));}
#line 674 "parser.cc"
    break;

  case 10:
#line 124 "parser.y"
                                                         { (yylhs.value.STMT) = new ArrayFormal((yystack_[5].value.TYPE), (yystack_[4].value.IDENT), (yystack_[2].value.EXPR)); }
#line 680 "parser.cc"
    break;

  case 11:
#line 128 "parser.y"
              { (yylhs.value.TYPE) = Type::int_; }
#line 686 "parser.cc"
    break;

  case 12:
#line 131 "parser.y"
                                                             { (yylhs.value.STMT) = new FuncDeclNode(Type::void_, (yystack_[4].value.IDENT), (yystack_[2].value.FORMALS), (yystack_[0].value.BLOCK)); }
#line 692 "parser.cc"
    break;

  case 13:
#line 132 "parser.y"
                                                                 { (yylhs.value.STMT) = new FuncDeclNode((yystack_[5].value.TYPE), (yystack_[4].value.IDENT), (yystack_[2].value.FORMALS), (yystack_[0].value.BLOCK)); }
#line 698 "parser.cc"
    break;

  case 14:
#line 133 "parser.y"
                                                          { cout << "invalid return type" << endl; yyerrok; }
#line 704 "parser.cc"
    break;

  case 15:
#line 137 "parser.y"
               { /* no param */ (yylhs.value.FORMALS) = nullptr;}
#line 710 "parser.cc"
    break;

  case 16:
#line 138 "parser.y"
             { (yylhs.value.FORMALS) = nullptr;}
#line 716 "parser.cc"
    break;

  case 17:
#line 139 "parser.y"
        { (yylhs.value.FORMALS) = (yystack_[0].value.FORMALS); }
#line 722 "parser.cc"
    break;

  case 18:
#line 142 "parser.y"
                  { (yylhs.value.FORMALS) = new Formals(); (yylhs.value.FORMALS)->formals.push_back(static_cast<Formal*>((yystack_[0].value.STMT))); }
#line 728 "parser.cc"
    break;

  case 19:
#line 143 "parser.y"
                                   { (yystack_[2].value.FORMALS)->formals.push_back(static_cast<Formal*>((yystack_[0].value.STMT))); }
#line 734 "parser.cc"
    break;

  case 20:
#line 147 "parser.y"
                   { (yylhs.value.STMT) = new Formal((yystack_[1].value.TYPE), (yystack_[0].value.IDENT)); }
#line 740 "parser.cc"
    break;

  case 21:
#line 148 "parser.y"
                                     {(yylhs.value.STMT) = new ArrayFormal((yystack_[3].value.TYPE), (yystack_[2].value.IDENT)); }
#line 746 "parser.cc"
    break;

  case 22:
#line 152 "parser.y"
                                        { (yylhs.value.BLOCK) = (yystack_[1].value.BLOCK); }
#line 752 "parser.cc"
    break;

  case 23:
#line 153 "parser.y"
                                              { (yylhs.value.BLOCK) = nullptr;}
#line 758 "parser.cc"
    break;

  case 24:
#line 156 "parser.y"
                { (yylhs.value.BLOCK) = new BlockNode(); (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 764 "parser.cc"
    break;

  case 25:
#line 157 "parser.y"
                          { (yystack_[1].value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 770 "parser.cc"
    break;

  case 26:
#line 160 "parser.y"
      { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 776 "parser.cc"
    break;

  case 27:
#line 161 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 782 "parser.cc"
    break;

  case 28:
#line 162 "parser.y"
                      { (yylhs.value.STMT) = (yystack_[0].value.BLOCK);  }
#line 788 "parser.cc"
    break;

  case 29:
#line 163 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 794 "parser.cc"
    break;

  case 30:
#line 164 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 800 "parser.cc"
    break;

  case 31:
#line 165 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 806 "parser.cc"
    break;

  case 32:
#line 169 "parser.y"
                                                         {(yylhs.value.STMT) = new SelectNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
#line 812 "parser.cc"
    break;

  case 33:
#line 170 "parser.y"
                                           {(yylhs.value.STMT) = new SelectNode((yystack_[4].value.EXPR), (yystack_[2].value.STMT), (yystack_[0].value.STMT)); }
#line 818 "parser.cc"
    break;

  case 34:
#line 173 "parser.y"
                     { (yylhs.value.STMT) = new ExpStmtNode((yystack_[1].value.EXPR)); }
#line 824 "parser.cc"
    break;

  case 35:
#line 174 "parser.y"
               { (yylhs.value.STMT) = nullptr; }
#line 830 "parser.cc"
    break;

  case 36:
#line 177 "parser.y"
                                              { (yylhs.value.STMT) = new WhileNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
#line 836 "parser.cc"
    break;

  case 37:
#line 180 "parser.y"
                          { (yylhs.value.STMT) = new ReturnNode(); }
#line 842 "parser.cc"
    break;

  case 38:
#line 181 "parser.y"
                              { (yylhs.value.STMT) = new ReturnNode((yystack_[1].value.EXPR)); }
#line 848 "parser.cc"
    break;

  case 39:
#line 184 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
#line 854 "parser.cc"
    break;

  case 40:
#line 185 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[1].value.EXPR);}
#line 860 "parser.cc"
    break;

  case 41:
#line 186 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::plus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 866 "parser.cc"
    break;

  case 42:
#line 187 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::minus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 872 "parser.cc"
    break;

  case 43:
#line 188 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::mul, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 878 "parser.cc"
    break;

  case 44:
#line 189 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::div, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 884 "parser.cc"
    break;

  case 45:
#line 190 "parser.y"
                             { (yylhs.value.EXPR) = new UnaryOperator(UaOpt::neg, (yystack_[0].value.EXPR));}
#line 890 "parser.cc"
    break;

  case 46:
#line 191 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR)); }
#line 896 "parser.cc"
    break;

  case 47:
#line 192 "parser.y"
                             { (yylhs.value.EXPR) = new MethodCallNode((yystack_[3].value.IDENT), (yystack_[1].value.ARGS)); }
#line 902 "parser.cc"
    break;

  case 48:
#line 193 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR));}
#line 908 "parser.cc"
    break;

  case 49:
#line 194 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
#line 914 "parser.cc"
    break;

  case 50:
#line 195 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.EXPR);}
#line 920 "parser.cc"
    break;

  case 51:
#line 196 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.IDENT); }
#line 926 "parser.cc"
    break;

  case 52:
#line 199 "parser.y"
                                              { (yylhs.value.IDENT) = new ArrayRef((yystack_[3].value.STR), (yystack_[1].value.EXPR)); }
#line 932 "parser.cc"
    break;

  case 53:
#line 201 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::less, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 938 "parser.cc"
    break;

  case 54:
#line 202 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::greater,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 944 "parser.cc"
    break;

  case 55:
#line 203 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::equal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 950 "parser.cc"
    break;

  case 56:
#line 204 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::nequal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 956 "parser.cc"
    break;

  case 57:
#line 205 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::eless,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 962 "parser.cc"
    break;

  case 58:
#line 206 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::egreater ,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 968 "parser.cc"
    break;

  case 59:
#line 209 "parser.y"
                    { (yylhs.value.EXPR) = new NumNode(std::stoi(*(yystack_[0].value.STR))); delete (yystack_[0].value.STR); }
#line 974 "parser.cc"
    break;

  case 60:
#line 212 "parser.y"
             { (yylhs.value.ARGS) = nullptr; }
#line 980 "parser.cc"
    break;

  case 61:
#line 213 "parser.y"
            { (yylhs.value.ARGS) = new ArgsNode(); (yylhs.value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 986 "parser.cc"
    break;

  case 62:
#line 214 "parser.y"
                      { (yystack_[2].value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 992 "parser.cc"
    break;


#line 996 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char Parser::yypact_ninf_ = -68;

  const signed char Parser::yytable_ninf_ = -4;

  const short
  Parser::yypact_[] =
  {
      50,    -8,    14,   -68,     9,    53,   -68,   -68,    14,   -68,
      15,   -68,    38,   -68,   -68,     6,    14,    46,    69,   -68,
      69,     2,    47,    56,   -68,    67,    78,   -68,    81,    80,
     -68,     2,     2,    18,   207,    89,   -68,   -68,    88,    60,
     -68,    56,    15,    56,     2,   151,   -68,     2,     2,    90,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   -68,   -68,   -68,    95,   204,    96,   -68,    14,   -68,
      87,   -68,   -68,   -68,   -68,   -68,   118,   -68,   -68,   -68,
     218,   -68,   228,   228,    32,   -68,    83,    83,   -68,   -68,
      64,    64,    64,    64,    64,    64,   228,     2,   -68,   136,
       2,    57,   -68,   -68,   -68,   -68,     2,   -68,   166,   -68,
     181,   228,   104,   104,    82,   -68,   104,   -68
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,    11,     0,     0,     5,     7,     0,     8,
       0,     4,     0,     1,     6,     0,     0,     0,    15,     9,
      15,     0,    20,     0,    16,     0,    17,    18,     0,     4,
      59,     0,     0,    51,     0,    50,    39,    49,     0,     0,
      14,     0,     0,     0,     0,     0,    45,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    35,    23,     0,     0,     0,    27,     0,    28,
       0,    24,    29,    26,    30,    31,     0,    12,    19,    13,
       0,    40,    46,    61,     0,    10,    41,    42,    43,    44,
      54,    53,    55,    57,    58,    56,    48,     0,    37,     0,
       0,     0,    22,    25,    34,    52,     0,    47,     0,    38,
       0,    62,     0,     0,    32,    36,     0,    33
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -68,   -68,    -1,   -68,   106,    13,    42,   -68,    98,   -68,
      -2,   -19,   -68,   -67,   -68,   -68,   -68,   -68,   -21,   -68,
     -68,   -68,   -68
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,    33,     5,     6,    67,    68,     9,    25,    26,
      27,    69,    70,    71,    72,    73,    74,    75,    76,    35,
      36,    37,    84
  };

  const signed char
  Parser::yytable_[] =
  {
      34,    12,    10,   103,    40,    29,    30,    15,    17,    13,
      45,    46,    31,     7,    19,    22,    20,    11,     7,    32,
      21,     3,    77,    80,    79,    47,    82,    83,    48,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      78,   106,     8,   107,    99,   114,   115,     8,    18,   117,
      -3,     1,    16,    -2,     1,     2,     3,    23,     2,     3,
      16,    38,    16,    29,    30,    19,     3,   101,    62,    39,
      31,    21,    63,    39,    24,     3,   108,    32,    41,   110,
      50,    51,    52,    53,    16,   111,    64,    42,    65,    66,
      29,    30,    43,     3,    44,    62,    60,    31,    85,   102,
      39,    52,    53,    61,    32,    97,   100,    29,    30,   116,
       3,    14,    62,    64,    31,    65,    66,    39,    28,     0,
       0,    32,     0,     0,     0,     0,   104,     0,     0,     0,
      64,     0,    65,    66,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   109,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    81,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   112,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   113,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    29,    30,     0,
       0,     0,    98,     0,    31,     0,     0,     0,     0,     0,
       0,    32,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   105,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59
  };

  const signed char
  Parser::yycheck_[] =
  {
      21,     2,    10,    70,    23,     3,     4,     8,    10,     0,
      31,    32,    10,     0,     8,    16,    10,     3,     5,    17,
      14,     6,    41,    44,    43,     7,    47,    48,    10,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      42,     9,     0,    11,    65,   112,   113,     5,    10,   116,
       0,     1,    10,     0,     1,     5,     6,    11,     5,     6,
      18,    14,    20,     3,     4,     8,     6,    68,     8,    13,
      10,    14,    12,    13,     5,     6,    97,    17,    11,   100,
      16,    17,    18,    19,    42,   106,    26,     9,    28,    29,
       3,     4,    11,     6,    14,     8,     7,    10,     8,    12,
      13,    18,    19,    15,    17,    10,    10,     3,     4,    27,
       6,     5,     8,    26,    10,    28,    29,    13,    20,    -1,
      -1,    17,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      26,    -1,    28,    29,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    11,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    11,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     3,     4,    -1,
      -1,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,     5,     6,    33,    35,    36,    37,    38,    39,
      10,     3,    34,     0,    36,    34,    38,    42,    10,     8,
      10,    14,    34,    11,     5,    40,    41,    42,    40,     3,
       4,    10,    17,    34,    50,    51,    52,    53,    14,    13,
      43,    11,     9,    11,    14,    50,    50,     7,    10,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       7,    15,     8,    12,    26,    28,    29,    37,    38,    43,
      44,    45,    46,    47,    48,    49,    50,    43,    42,    43,
      50,    11,    50,    50,    54,     8,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    10,     8,    50,
      10,    34,    12,    45,     8,    15,     9,    11,    50,     8,
      50,    50,    11,    11,    45,    45,    27,    45
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    32,    33,    33,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    52,    52,    52,    52,    52,    52,    53,
      54,    54,    54
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     1,     2,     1,     1,     3,
       6,     1,     6,     6,     5,     0,     1,     1,     1,     3,
       2,     4,     3,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     5,     7,     2,     1,     5,     2,     3,     1,
       3,     3,     3,     3,     3,     2,     3,     4,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     1,
       0,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_CONST", "VOID", "INT", "ASSIGN", "SEMI", "COMMA", "LPAREN",
  "RPAREN", "RBRACE", "LBRACE", "LBRACKET", "RBRACKET", "PLUS", "MINUS",
  "MUL", "DIV", "GREATER", "LESS", "EQUAL", "ELESS", "EGREATER", "NEQUAL",
  "IF", "ELSE", "RETURN", "WHILE", "NEG", "NO_ELSE", "$accept", "program",
  "id", "declaration_list", "declaration", "var_declaration", "var_type",
  "func_declaration", "params", "param_list", "param", "compound_stmt",
  "stmt_list", "stmt", "selection_stmt", "expr_stmt", "iteration_stmt",
  "return_stmt", "expr", "array_ref", "comparision", "numeric", "args", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   107,   107,   108,   111,   115,   116,   119,   120,   123,
     124,   128,   131,   132,   133,   137,   138,   139,   142,   143,
     147,   148,   152,   153,   156,   157,   160,   161,   162,   163,
     164,   165,   169,   170,   173,   174,   177,   180,   181,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   199,   201,   202,   203,   204,   205,   206,   209,
     212,   213,   214
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
    };
    const int user_token_number_max_ = 286;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= user_token_number_max_)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "parser.y"
} // ccbhj
#line 1453 "parser.cc"

#line 216 "parser.y"

void ccbhj::Parser::error(const Parser::location_type& l, const std::string& m) {
    drv.error(l, m);
}
